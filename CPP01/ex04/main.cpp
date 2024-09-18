#include "File.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    File file(argv[1]);

    if (!file.isValid()) {
        std::cerr << "Error: file " << argv[1] << " could not be processed." << std::endl;
        return 1;
    }

    if (!file.replace(argv[2], argv[3])) {
        std::cerr << "Error: replacement failed." << std::endl;
        return 1;
    }

    return 0;
}
