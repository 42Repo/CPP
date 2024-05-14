/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:17:21 by asuc              #+#    #+#             */
/*   Updated: 2024/05/14 13:15:26 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

# include "Contact.hpp"

class PhoneBook : public Contact
{
    public:
        PhoneBook();
        ~PhoneBook();
        void add();
        void search();
        void print();
    private:
        int m_index;
        Contact m_contacts[8];
};


#endif // __PHONEBOOK_H__