/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:43:24 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 17:43:47 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {
    m_name = "default";
    std::cout << "Zombie " << m_name << " is born." << std::endl;
}

Zombie::~Zombie() { std::cout << "Zombie " << m_name << " is dead." << std::endl; }

void Zombie::announce() const {
    std::cout << "Zombie " << m_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { m_name = name; }