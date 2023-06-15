#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <list>

class PmergeMe
{
	public:
		// Constructors
		PmergeMe(int size);
		
		// Destructor
		~PmergeMe();
		
		// Operators
		
		// Exceptions
		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};
		
		void push(std::string lit);
		void printCon1(void) const;
		void printCon2(void) const;

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PmergeMe &assign);

		typedef std::vector<int> Container1;
		typedef std::list<int> Container2;

		const size_t _size;
		Container1 _con1;
		Container2 _con2;
};

std::ostream & operator<<(std::ostream & os, const PmergeMe & p);

#endif