#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
  public:
    Brain(void);
    Brain(const Brain &a);
    Brain &operator=(const Brain &a);
    virtual ~Brain(void);
    void        setIdea(int i, std::string idea);
    std::string getIdea(int i) const;

  protected:
    std::string _ideas[100];
};

#endif // BRAIN_H
