/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:18:46 by asuc              #+#    #+#             */
/*   Updated: 2024/05/14 13:47:24 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      for (int j = 0; argv[i][j]; j++)
        std::cout << (char)toupper(argv[i][j]);
    }
    std::cout << std::endl;
  } else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  return 0;
}
