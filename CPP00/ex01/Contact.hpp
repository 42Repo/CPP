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
