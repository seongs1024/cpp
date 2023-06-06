#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <string>
# include "AType.hpp"

class Float: public virtual AType
{
	public:
		// Constructors
		Float(std::string &lit);
		Float(const Float &copy);
		
		// Destructor
		virtual ~Float();
		
		// Operators
		Float & operator=(const Float &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Float();

		float _value;
		
};

#endif