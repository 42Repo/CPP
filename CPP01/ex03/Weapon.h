/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:48:29 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:13:38 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
  public:
    Weapon(std::string type);
    Weapon();
    ~Weapon();
    const std::string &getType() const;
    void               setType(std::string type);

  private:
    std::string _type;
};

#endif // WEAPON_H