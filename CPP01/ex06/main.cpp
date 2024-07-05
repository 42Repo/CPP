/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:30 by asuc              #+#    #+#             */
/*   Updated: 2024/07/05 18:05:07 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int argc, char **argv) {
    Harl harl;

    if (argc == 2) {
        harl.complain(argv[1]);
    } else {
        harl.complain("No argument passed!");
    }
    return 0;
}