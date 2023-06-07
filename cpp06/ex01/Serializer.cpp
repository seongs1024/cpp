#include "Serializer.hpp"

// Constructors
Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
}


// Destructor
Serializer::~Serializer()
{
}


// Operators
Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}