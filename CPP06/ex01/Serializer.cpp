#include "Serializer.h"

Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
