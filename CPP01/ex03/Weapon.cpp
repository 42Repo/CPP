/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:48:35 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:21:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string type) { _type = type; }

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const { return _type; }

void Weapon::setType(std::string type) { _type = type; }
