/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:20:11 by asuc              #+#    #+#             */
/*   Updated: 2024/05/20 16:30:39 by asuc             ###   ########.fr       */
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
    std::string input;

    while (1) {
        std::cout << line;
        if (!(std::getline(std::cin, input))) {
            return "";
        }
        if (!input.empty()) {
            return input;
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
    for (int i = 0; i < 8; i++) {
        if (contacts[i].getFirstName() != "") {
            return 0;
        }
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
    for (int i = 0; i < 8; i++) {
        if (is_empty(contacts, i) == 1) {
            break;
        }
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << shorten(contacts[i].getNickname()) << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl << std::endl;
    return 0;
}

void PhoneBook::add() {
    std::string tmp;

    if (m_index == 8) {
        m_index = 0;
    }
    if ((tmp = getNextLine("Enter first name: ")).empty()) {
        return throw std::exception();
    }
    m_contacts[m_index].setFirstName(tmp);
    if ((tmp = getNextLine("Enter last name: ")).empty()) {
        return throw std::exception();
    }
    m_contacts[m_index].setLastName(tmp);
    if ((tmp = getNextLine("Enter nickname: ")).empty()) {
        return throw std::exception();
    }
    m_contacts[m_index].setNickname(tmp);
    if ((tmp = getNextLine("Enter phone number: ")).empty()) {
        return throw std::exception();
    }
    m_contacts[m_index].setPhoneNumber(tmp);
    if ((tmp = getNextLine("Enter darkest secret: ")).empty()) {
        return throw std::exception();
    }
    m_contacts[m_index].setDarkestSecret(tmp);
    std::cout << "\033[32mContact added !\033[0m" << std::endl;
    std::cout << std::endl;
    m_index++;
}

void PhoneBook::search() const {
    std::string tmp;
    int         index;

    if (print(m_contacts, m_index) == 1) {
        return;
    }
    while (1) {
        if ((tmp = getNextLine("Enter index: ")).empty()) {
            return throw std::exception();
        }
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
