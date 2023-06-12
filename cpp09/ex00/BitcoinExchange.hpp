#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(const char * price_db_path, const char * temp);
		
		// Destructor
		~BitcoinExchange();
		
		// Operators
		
		// Getters / Setters
		
		// Exceptions
		class NotPositiveNumberException : public std::exception {
			virtual const char* what() const throw();
		};
		class FileOpenException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		class BadInputException : public std::exception {
			virtual const char* what() const throw();
		};
		class TooLargeNumberException : public std::exception {
			virtual const char* what() const throw();
		};
		class PriceDbNotExistsException : public std::exception {
			virtual const char* what() const throw();
		};
		class CorruptedFileException : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		typedef std::map<std::string, double> Prices;

		Prices makePrices(const char * price_db_path);

		Prices prices;
};

#endif