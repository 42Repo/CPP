/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:38:52 by asuc              #+#    #+#             */
/*   Updated: 2024/05/20 16:02:24 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"
#include <cstddef>
#include <fstream>

File::File(std::string const &filename) {
    _filename = filename;
    open(_filename);
    if (!is_open()) {
        std::cerr << "Error: " << _filename << " could not be opened." << std::endl;
        exit(1);
    }
}

File::~File() {
    if (is_open())
        close();
}

std::string File::getFilename() const { return _filename; }

int File::setFilename(std::string const &filename) {
    _filename = filename;
    open(_filename);
    if (!is_open()) {
        std::cerr << "Error: " << _filename << " could not be opened." << std::endl;
        return 1;
    }
    return 0;
}

static int checkOpen(std::ifstream &file, std::string const &filename) {
    if (!file.is_open()) {
        std::cerr << "Error: " << filename << " could not be opened." << std::endl;
        return 1;
    }
    return 0;
}

int File::replace(std::string const &s1, std::string const &s2) {
    std::string   line;
    std::string   line2;
    std::ofstream outputfile(_filename + ".replace");
    std::ifstream inputFile(_filename);
    size_t        pos;

    if (checkOpen(inputFile, _filename))
        return 1;
    if (checkOpen(inputFile, _filename + ".replace")) {
        inputFile.close();
        return 1;
    }
    while (std::getline(inputFile, line)) {
        pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line2 = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            line = line2;
            pos += s2.length();
        }
        outputfile << line << std::endl;
    }
    outputfile.close();
    inputFile.close();
    return 0;
}
