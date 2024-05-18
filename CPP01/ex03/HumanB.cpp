/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:49:03 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:27:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(std::string name) {
    _name = name;
    _weapon = nullptr;
    std::cout << _name << " is born without a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
    std::cout << _name << " has now a " << _weapon->getType() << std::endl;
}

void HumanB::attack() {
    if (_weapon == nullptr) {
        std::cout << _name << " has no weapon" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
