#ifndef FILE_H
#define FILE_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class File {
  public:
    File(const std::string &filename);
    ~File();
    bool replace(const std::string &s1, const std::string &s2);
    bool isValid() const;

  private:
    std::string   _filename;
    std::ifstream _inputFile;
    std::ofstream _outputFile;
    bool          openFiles();
};

#endif // FILE_H
