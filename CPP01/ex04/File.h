/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:38:38 by asuc              #+#    #+#             */
/*   Updated: 2024/05/20 16:01:03 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include <iostream>
#include <string>

class File : public std::ifstream {
  public:
    File(std::string const &filename);
    ~File();
    int         setFilename(std::string const &filename);
    std::string getFilename() const;
    int         replace(std::string const &s1, std::string const &s2);

  private:
    std::string _filename;
};

#endif // __FILE_H__