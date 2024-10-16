#include "File.h"

File::File(const std::string &filename) : _filename(filename) {
    if (!openFiles()) {
        std::cerr << "Error: could not open file " << _filename << std::endl;
    }
}

File::~File() {
    if (_inputFile.is_open()) {
        _inputFile.close();
    }
    if (_outputFile.is_open()) {
        _outputFile.close();
    }
}

bool File::isValid() const { return _inputFile.is_open() && _outputFile.is_open(); }

bool File::openFiles() {
    _inputFile.open(_filename.c_str());
    if (!_inputFile.is_open()) {
        return false;
    }
    _outputFile.open((_filename + ".replace").c_str());
    if (!_outputFile.is_open()) {
        return false;
    }
    return true;
}

bool File::replace(const std::string &s1, const std::string &s2) {
    if (!_inputFile.is_open() || !_outputFile.is_open()) {
        std::cerr << "Error: file streams are not open." << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(_inputFile, line)) {
        std::string newLine;
        size_t      pos = 0;

        while (pos < line.length()) {
            size_t foundPos = line.find(s1, pos);
            if (foundPos != std::string::npos) {
                newLine.append(line, pos, foundPos - pos);
                newLine.append(s2);
                pos = foundPos + s1.length();
            } else {
                newLine.append(line, pos, line.length() - pos);
                break;
            }
        }
        _outputFile << newLine << std::endl;
    }
    return true;
}
