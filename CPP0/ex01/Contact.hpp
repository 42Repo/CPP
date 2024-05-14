/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:19:09 by asuc              #+#    #+#             */
/*   Updated: 2024/05/14 13:45:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>

class Contact {
public:
  Contact();
  ~Contact();
  void setFirstName(std::string firstName);
  void setLastName(std::string lastName);
  void setNickname(std::string nickname);
  void setPhoneNumber(std::string phoneNumber);
  void setDarkestSecret(std::string darkestSecret);
  std::string getFirstName();
  std::string getLastName();
  std::string getNickname();
  std::string getPhoneNumber();
  std::string getDarkestSecret();

private:
  std::string m_firstName;
  std::string m_lastName;
  std::string m_nickname;
  std::string m_phoneNumber;
  std::string m_darkestSecret;
};

#endif // __CONTACT_H__