/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:17:21 by asuc              #+#    #+#             */
/*   Updated: 2024/05/14 13:46:05 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook : public Contact {
public:
  PhoneBook();
  ~PhoneBook();
  void add();
  void search();
  void print();

private:
  Contact m_contacts[8];
  int m_index;
};

#endif // __PHONEBOOK_H__