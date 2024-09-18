#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl {
  public:
    Harl();
    ~Harl();
    void complain(std::string level);

  private:
    void _debug(void) const;
    void _info(void) const;
    void _warning(void) const;
    void _error(void) const;
};

#endif // HARL_H
