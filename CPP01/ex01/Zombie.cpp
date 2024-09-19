#include "Zombie.h"

Zombie::Zombie(void) {
    m_name = "default";
    std::cout << "Zombie " << m_name << " is born." << std::endl;
}

Zombie::Zombie(std::string name) {
    m_name = name;
    std::cout << "Zombie " << m_name << " is born." << std::endl;
}

Zombie::~Zombie(void) { std::cout << "Zombie " << m_name << " is dead." << std::endl; }

void Zombie::announce(void) const {
    std::cout << "Zombie " << m_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { m_name = name; }
