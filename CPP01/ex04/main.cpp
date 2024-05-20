/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:15 by asuc              #+#    #+#             */
/*   Updated: 2024/05/20 16:13:29 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }
    File file(argv[1]);
    file.replace(argv[2], argv[3]);

    return 0;
}