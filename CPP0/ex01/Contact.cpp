/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:19:07 by asuc              #+#    #+#             */
/*   Updated: 2024/05/14 13:24:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName()
{
	return (this->m_firstName);
}

std::string Contact::getLastName()
{
	return (this->m_lastName);
}

std::string Contact::getNickname()
{
	return (this->m_nickname);
}

std::string Contact::getPhoneNumber()
{
	return (this->m_phoneNumber);	
}

std::string Contact::getDarkestSecret()
{
	return (this->m_darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
	this->m_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->m_lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	this->m_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->m_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->m_darkestSecret = darkestSecret;
}

Contact::Contact()
{
}

Contact::~Contact()
{
}
