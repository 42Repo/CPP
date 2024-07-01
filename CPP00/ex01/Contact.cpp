/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:59:14 by asuc              #+#    #+#             */
/*   Updated: 2024/07/01 15:59:15 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName() const { return (m_firstName); }

std::string Contact::getLastName() const { return (m_lastName); }

std::string Contact::getNickname() const { return (m_nickname); }

std::string Contact::getPhoneNumber() const { return (m_phoneNumber); }

std::string Contact::getDarkestSecret() const { return (m_darkestSecret); }

void Contact::setLastName(const std::string &lastName) { m_lastName = lastName; }

void Contact::setNickname(const std::string &nickname) { m_nickname = nickname; }

void Contact::setFirstName(const std::string &firstName) { m_firstName = firstName; }

void Contact::setPhoneNumber(const std::string &phoneNumber) { m_phoneNumber = phoneNumber; }

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    m_darkestSecret = darkestSecret;
}
