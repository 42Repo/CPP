#pragma once

#include <iostream>
#include <stdint.h>
#include <string>

struct Data {
    std::string s1;
    std::string s2;
    long int    n;
};

class Serializer {
  public:
    static uintptr_t serialize(Data *ptr);
    static Data     *deserialize(uintptr_t raw);

  private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
};
