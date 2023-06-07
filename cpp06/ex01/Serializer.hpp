#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <exception>
# include "Data.hpp"

class Serializer
{
	public:
		// Constructors
		Serializer(const Serializer &copy);
		
		// Destructor
		~Serializer();
		
		// Operators
		Serializer & operator=(const Serializer &assign);
		
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);

	private:
		Serializer();
		
};

#endif