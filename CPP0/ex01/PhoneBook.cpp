/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:20:11 by asuc              #+#    #+#             */
/*   Updated: 2024/05/16 19:48:53 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() { m_index = 0; }

PhoneBook::~PhoneBook() {}

/**
 * @brief Recupère la prochaine ligne de l'entrée standard
 *
 * @param line La ligne à afficher avant de récupérer la prochaine
 * @return std::string La prochaine ligne
 */
static std::string getNextLine(std::string line) {
    std::string tmp;

    while (1) {
        std::cout << line;
        if (!(std::getline(std::cin, tmp))) {
            std::cout << "\033[31m\nExiting due to input error or EOF.\033[0m" << std::endl;
            exit(1);
        }
        if (tmp != "") {
            return tmp;
        }
    }
}

/**
 * @brief Verifie si le contact est vide
 *
 * @param contacts  La liste de contact
 * @param index L'index du contact
 * @return int 0 si le contact n'est pas vide, 1 sinon
 */
static int is_empty(const Contact contacts[8], int index) {
    if (contacts[index].getFirstName() == "") {
        return 1;
    }
    return 0;
}

/**
 * @brief Si la chaine de caractère est plus longue que 10 caractères, affiche les 9 premiers
 * caractères suivis de trois points
 *
 *
 * @param str La chaine de caractère à afficher
 */
static std::string shorten(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}

/**
 * @brief Verifie si la liste de contact est vide
 *
 * @param contacts La liste de contact
 * @return int 0 si la liste n'est pas vide, 1 sinon
 */
static int is_all_empty(const Contact contacts[8]) {
    int i = 0;

    while (i < 8) {
        if (contacts[i].getFirstName() != "") {
            return 0;
        }
        i++;
    }
    std::cout << "\033[31mThe list is empty\033[0m" << std::endl;
    return 1;
}

/**
 * @brief Affiche les contacts de la liste
 *
 */
static int print(const Contact contacts[8], int index) {

    if (is_all_empty(contacts) == 1) {
        return 1;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < index; i++) {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl << std::endl;
    return 0;
}

/**
 * @brief Ajoute un contact à la liste
 *
 */
void PhoneBook::add() {
    std::string tmp;

    if (m_index == 8) {
        m_index = 0;
    }
    tmp = getNextLine("Enter first name: ");
    m_contacts[m_index].setFirstName(tmp);
    tmp = getNextLine("Enter last name: ");
    m_contacts[m_index].setLastName(tmp);
    tmp = getNextLine("Enter nickname: ");
    m_contacts[m_index].setNickname(tmp);
    tmp = getNextLine("Enter phone number: ");
    m_contacts[m_index].setPhoneNumber(tmp);
    tmp = getNextLine("Enter darkest secret: ");
    m_contacts[m_index].setDarkestSecret(tmp);
    std::cout << "\033[32mContact added !\033[0m" << std::endl;
    std::cout << std::endl;
    m_index++;
}

/**
 * @brief Affiche un resumer des contact et demande l'index du contact à afficher plus
 * précisément
 *
 */
void PhoneBook::search() const {
    std::string tmp;
    int         index;

    if (print(m_contacts, m_index) == 1) {
        return;
    }
    while (1) {
        tmp = getNextLine("Enter the index of the contact: ");
        if (tmp.length() == 1 && tmp[0] >= '1' && tmp[0] <= '8' &&
            !is_empty(m_contacts, tmp[0] - '0' - 1)) {
            index = tmp[0] - '0';
            break;
        }
        std::cout << "Invalid index" << std::endl;
    }
    std::cout << std::endl << "First name\t: " << m_contacts[index - 1].getFirstName() << std::endl;
    std::cout << "Last name\t: " << m_contacts[index - 1].getLastName() << std::endl;
    std::cout << "Nickname\t: " << m_contacts[index - 1].getNickname() << std::endl;
    std::cout << "Phone number\t: " << m_contacts[index - 1].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret\t: " << m_contacts[index - 1].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}
