/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:46 by asuc              #+#    #+#             */
/*   Updated: 2024/06/03 17:57:54 by asuc             ###   ########.fr       */
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
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif // __HARL_H__