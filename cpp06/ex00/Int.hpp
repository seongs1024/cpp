#ifndef INT_HPP
# define INT_HPP

# include <string>
# include "AType.hpp"

class Int: public virtual AType
{
	public:
		// Constructors
		Int(std::string &lit);
		Int(const Int &copy);
		
		// Destructor
		virtual ~Int();
		
		// Operators
		Int & operator=(const Int &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Int();

		int _value;
		
};

#endif