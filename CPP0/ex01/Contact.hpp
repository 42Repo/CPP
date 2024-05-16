/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:19:09 by asuc              #+#    #+#             */
/*   Updated: 2024/05/15 23:51:19 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iomanip>
#include <iostream>

class Contact {
  public:
    void        setFirstName(const std::string &firstName);
    void        setLastName(const std::string &lastName);
    void        setNickname(const std::string &nickname);
    void        setPhoneNumber(const std::string &phoneNumber);
    void        setDarkestSecret(const std::string &darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

  private:
    std::string m_firstName;
    std::string m_lastName;
    std::string m_nickname;
    std::string m_phoneNumber;
    std::string m_darkestSecret;
};

#endif // __CONTACT_H__