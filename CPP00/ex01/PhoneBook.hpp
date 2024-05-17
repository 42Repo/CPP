/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:17:21 by asuc              #+#    #+#             */
/*   Updated: 2024/05/17 18:33:41 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook : public Contact {
  public:
    /**
     * @brief Construct a new Phone Book object
     *
     */
    PhoneBook();

    /**
     * @brief Destroy the Phone Book object
     *
     */
    ~PhoneBook();

    /**
     * @brief Ajoute un contact à la liste
     *
     * @return int 1 si le contact est vide, 0 sinon
     */
    int add();

    /**
     * @brief Affiche un resumer des contact et demande l'index du contact à afficher plus
     * précisément
     *
     * @return int 1 si l'index est invalide, 0 sinon
     */
    int search() const;

  private:
    Contact m_contacts[8];
    int     m_index;
};

#endif // __PHONEBOOK_H__