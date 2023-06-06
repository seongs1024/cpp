#ifndef NEGATIVE_INF_HPP
# define NEGATIVE_INF_HPP

# include <exception>
# include "AType.hpp"

class NegativeInf: public virtual AType
{
	public:
		// Constructors
		NegativeInf();
		NegativeInf(const NegativeInf &copy);
		
		// Destructor
		virtual ~NegativeInf();
		
		// Operators
		NegativeInf & operator=(const NegativeInf &assign);

		// Exceptions
		class NegativeInfException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;

};

#endif