#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include <string>
# include "AType.hpp"

class Double: public virtual AType
{
	public:
		// Constructors
		Double(std::string &lit);
		Double(const Double &copy);
		
		// Destructor
		virtual ~Double();
		
		// Operators
		Double & operator=(const Double &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Double();

		double _value;
		
};

#endif