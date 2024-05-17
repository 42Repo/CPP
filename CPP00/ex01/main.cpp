/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:02:18 by asuc              #+#    #+#             */
/*   Updated: 2024/05/17 21:04:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook   phoneBook;
    std::string command;

    while (1) {
        std::cout << "Enter a command: ";
        if (!(std::getline(std::cin, command))) {
            std::cout << "\033[31m\nExiting due to input error or EOF.\033[0m" << std::endl;
            break;
        }
        try {

            if (command == "ADD") {
                phoneBook.add();
            } else if (command.compare("SEARCH") == 0) {
                phoneBook.search();
            } else if (command.compare("EXIT") == 0)
                break;
            else
                std::cout << "\033[31mUsage: ADD | SEARCH | EXIT\033[0m" << std::endl;
        } catch (std::exception &e) {
            std::cout << "\033[31m\nExiting due to input error or EOF.\033[0m" << std::endl;
            return 1;
        }
    }
    return 0;
}