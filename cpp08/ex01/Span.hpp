#ifndef SPAN_HPP
# define SPAN_HPP

# include <list>

class Span
{
	public:
		// Constructors
		Span(unsigned int n);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);

		// Exceptions
		class OverCapacityException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoSpanFoundException : public std::exception {
			virtual const char* what() const throw();
		};

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		
	private:
		Span();
		std::list<int>::iterator next(std::list<int>::iterator iter, int n);

		unsigned int _capa;
		std::list<int> _list;
		int _shortest_span;
};

#endif