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
     */
    void add();

    /**
     * @brief Affiche un resumer des contact et demande l'index du contact à afficher plus
     * précisément
     *
     */
    void search() const;

  private:
    Contact m_contacts[8];
    int     m_index;
};

#endif // __PHONEBOOK_H__
