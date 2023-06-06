#ifndef NAN_HPP
# define NAN_HPP

# include <exception>
# include "AType.hpp"

class Nan: public virtual AType
{
	public:
		// Constructors
		Nan();
		Nan(const Nan &copy);
		
		// Destructor
		virtual ~Nan();
		
		// Operators
		Nan & operator=(const Nan &assign);

		// Exceptions
		class NanException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;

};

#endif