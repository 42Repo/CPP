/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:17:53 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:13:48 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.h"

class HumanB : public Weapon {
  public:
    HumanB(std::string name);
    void setWeapon(Weapon &weapon);
    void attack();

  private:
    std::string _name;
    Weapon     *_weapon;
};

#endif // __HUMANB_H__