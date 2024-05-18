/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:43:15 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 18:17:24 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
  public:
    Zombie(std::string name);
    ~Zombie();
    void announce();

  private:
    std::string m_name;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif // ZOMBIE_H