#include "Zombie.h"

Zombie::Zombie(std::string name) {
    m_name = name;
    std::cout << "Zombie " << m_name << " is born." << std::endl;
}

Zombie::~Zombie() { std::cout << "Zombie " << m_name << " is dead." << std::endl; }

void Zombie::announce() {
    std::cout << "Zombie " << m_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
