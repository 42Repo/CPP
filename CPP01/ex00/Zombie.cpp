/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:43:24 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 16:45:59 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string name) {
    m_name = name;
    std::cout << "Zombie " << m_name << " is born." << std::endl;
}

Zombie::~Zombie() { std::cout << "Zombie " << m_name << " is dead." << std::endl; }

void Zombie::announce() {
    std::cout << "Zombie " << m_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
