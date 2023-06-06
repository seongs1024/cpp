#ifndef POSITIVE_INF_HPP
# define POSITIVE_INF_HPP

# include <exception>
# include "AType.hpp"

class PositiveInf: public virtual AType
{
	public:
		// Constructors
		PositiveInf();
		PositiveInf(const PositiveInf &copy);
		
		// Destructor
		virtual ~PositiveInf();
		
		// Operators
		PositiveInf & operator=(const PositiveInf &assign);

		// Exceptions
		class PositiveInfException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;

};

#endif