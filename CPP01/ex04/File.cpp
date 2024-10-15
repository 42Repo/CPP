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
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        _outputFile << line << std::endl;
    }
    return true;
}
