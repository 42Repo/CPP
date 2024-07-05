/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:46 by asuc              #+#    #+#             */
/*   Updated: 2024/07/05 16:59:29 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl {
  public:
    Harl();
    ~Harl();
    void complain(std::string level);

  private:
    void _debug(void) const;
    void _info(void) const;
    void _warning(void) const;
    void _error(void) const;
};

#endif // __HARL_H__