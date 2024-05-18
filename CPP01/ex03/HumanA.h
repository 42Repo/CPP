/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:48:44 by asuc              #+#    #+#             */
/*   Updated: 2024/05/18 20:20:49 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA : public Weapon {
  public:
    HumanA(std::string name, Weapon &weapon);
    void attack();

  private:
    std::string _name;
    Weapon      _weapon;
};

#endif // HUMANA_H