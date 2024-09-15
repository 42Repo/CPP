#include "Brain.h"

Brain::Brain(void) { std::cout << "Brain Default constructor" << std::endl; }

Brain::Brain(const Brain &a) {
    std::cout << "Brain Copy constructor" << std::endl;
    for (int i = 0; i < 100; i++) {
        _ideas[i] = a._ideas[i];
    }
}

Brain &Brain::operator=(const Brain &a) {
    std::cout << "Brain Copy assignment operator constructor" << std::endl;
    if (this != &a) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = a._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(void) { std::cout << "Brain Destructor" << std::endl; }

void Brain::setIdea(int i, std::string idea) {
    if (i >= 0 && i < 100)
        _ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100)
        return _ideas[i];
}
