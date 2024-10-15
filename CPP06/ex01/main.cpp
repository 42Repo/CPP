#include "Serializer.h"

int main() {
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    std::cout << "data: " << &data << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "serialized: " << serialized << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Old data: " << &data << " New data: " << deserialized << std::endl;

    std::cout << "s1: " << deserialized->s1 << std::endl;
    std::cout << "n: " << deserialized->n << std::endl;
    std::cout << "s2: " << deserialized->s2 << std::endl;
    return 0;
}
