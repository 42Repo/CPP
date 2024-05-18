/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:46:59 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 17:42:09 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void) {
    const int N = 5;

    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombie[i].setName("Zombie" + std::to_string(i));
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}