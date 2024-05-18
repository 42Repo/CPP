/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:43:15 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 17:41:31 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie {
  public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce() const;

  private:
    std::string m_name;
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);