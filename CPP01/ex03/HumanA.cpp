/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:48:49 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:20:46 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) {
    _name = name;
    _weapon = weapon;
    std::cout << _name << " is born with a " << _weapon.getType() << std::endl;
}

void HumanA::attack() { std::cout << _name << " attacks with " << _weapon.getType() << std::endl; }
