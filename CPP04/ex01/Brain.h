#ifndef __BRAIN_H__
#define __BRAIN_H__

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

#endif // __BRAIN_H__