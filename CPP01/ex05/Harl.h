#ifndef __HARL_H__
#define __HARL_H__

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:51:46 by asuc              #+#    #+#             */
/*   Updated: 2024/05/20 16:39:09 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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