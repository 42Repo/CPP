/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:52 by asuc              #+#    #+#             */
/*   Updated: 2024/07/05 18:05:20 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i = 0;
    for (; i < 4; i++) {
        if (level == levels[i]) {
            break;
        }
    }
    switch (i) {
    case 0:
        _debug();
    case 1:
        _info();
    case 2:
        _warning();
    case 3:
        _error();
        break;
    default:
        std::cout << "What are you doing bro." << std::endl;
    }
}

void Harl::_debug(void) const { std::cout << "Wow i like debugging so much" << std::endl; }

void Harl::_info(void) const { std::cout << "That's some useful information" << std::endl; }

void Harl::_warning(void) const { std::cout << "Be careful" << std::endl; }

void Harl::_error(void) const { std::cout << "Something horrible happened" << std::endl; }
