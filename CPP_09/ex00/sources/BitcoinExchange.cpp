/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:11:01 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/21 16:43:43 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor for BitcoinExchange class
BitcoinExchange::BitcoinExchange(void) {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

// Destructor
BitcoinExchange::~BitcoinExchange(void) {}

// Assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_database = other._database;
	}
	return (*this);
}

/**
 * Imports the Bitcoin exchange database from a CSV file.
 * The file must be a valid CSV with a ".csv" extension, and should contain data in the
 * format "YYYY-MM-DD, value" on each line. Throws exceptions for invalid files or invalid data.
 */
void	BitcoinExchange::importDatabase(const std::string& database) {

	if (database.size() < 4 || database.substr(database.size() - 4) != ".csv")
		throw std::invalid_argument("Error: Invalid file extension. Expected a '.csv' file.");

	std::ifstream	file(database);

	if (!file.is_open())
		throw std::runtime_error("Error: Failure to open '" + database + "'");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: File '" + database + "' is empty");

	std::string line;
	const std::regex patternDatabase(R"(^(\d{4}-\d{2}-\d{2}),(-?\d+(?:\.\d+)?)$)");

	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.empty())
			throw std::runtime_error("Error: Invalid database content: Found empty line");
		
		// Validate line format using regex
		std::smatch sm;
		if (!std::regex_match(line, sm, patternDatabase))
			throw std::runtime_error("Error: Invalid database content: " + line);
		// Extract date and value from the matched line
		std::string databaseDate = sm[1].str();
		std::string databaseValue = sm[2].str();

		float	value = std::stof(databaseValue);
		auto result = _database.insert({databaseDate, value});
		// Handle duplicate dates: result.first points to existing element, if !resuld.second, key already exists
		if (!result.second)
			throw std::runtime_error("Error: Invalid database content: Found duplicate date (YYYY-MM-DD)");
	}
	file.close();
}

/**
 * Process the file containing Bitcoin exchange data.
 * Reads each line, validates the date and value, and computes the corresponding result using
 * the database values ('_database'). It displays the result for each valid line.
 * For any invalid line, it prints an error message for bad input.
 */
void	BitcoinExchange::processFile(const std::string& filename) {

	std::ifstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("Error: Failure to open '" + filename + "'");
	if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: File '" + filename + "' is empty");
	
	std::string	line;
	const std::regex patternInput(R"(^(\d{4}-\d{2}-\d{2}) \| (-?\d+(?:\.\d+)?)$)");
	
	std::getline(file, line);
	while (std::getline(file, line)) {	
		if (line.empty())
            continue;
        
		std::smatch sm;
        if (!std::regex_match(line, sm, patternInput)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

		std::string inputDate = sm[1].str();
		std::string inputValue = sm[2].str();

		if (!isValidDate(inputDate, line) || !isValidValue(inputValue, line))
			continue; 

		try {
			// Compute the result based on the exchange rate from the database
			float	value = std::stof(inputValue);
			float	rate = findDatabaseValue(inputDate);
			float	result = rate * value;
			std::cout << inputDate << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}

/**
 * Finds the closest exchange rate for the given date.
 * If the exact date is not found, it finds the nearest available date before the given date.
 * Throws an exception if no valid date is found before the given date.
 * 
 * Since std::map is ordered by keys, dates in "YYYY-MM-DD" format sort lexicographically,
 * so the chronological order works naturally
 */
float	BitcoinExchange::findDatabaseValue(const std::string& inputDate) {

	auto it = _database.lower_bound(inputDate);
	if (it != _database.end() && it->first == inputDate)
		return (it->second);

	if (it == _database.begin())
		throw std::runtime_error("Error: No exchange rate available for or before '" + inputDate + "'.");

	it--;
	return (it->second);
}

/**
 * Checks if the given year is a leap year.
 * A year is a leap year if it is divisible by 4, but not by 100 unless it is also divisible by 400.
 * Returns true if the year is a leap year, false otherwise.
 */
bool	BitcoinExchange::isLeapYear(int	year) const {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/**
 * Validates the input date format (YYYY-MM-DD).
 * If the date is invalid, it prints an error message with the original line from the input.
 * Returns true if the date is valid (including leap year checks), false otherwise.
 */
bool	BitcoinExchange::isValidDate(const std::string& inputDate, const std::string& line) const {

	int	year, month, day;
    try {
		year = std::stoi(inputDate.substr(0, 4));
        month = std::stoi(inputDate.substr(5, 2));
        day = std::stoi(inputDate.substr(8, 2));
    }
	catch (...) {
		std::cout << "Error: bad input => " << line << std::endl;
        return (false);
    }

    int	monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
		monthDays[1] = 29;
	
	if (month >= 1 && month <= 12 && day >= 1 && day <= monthDays[month - 1])
		return (true);
	std::cout << "Error: bad input => " << line << std::endl;
	return (false);
}

/**
 * Validates the input value format (positive number between 0 and 1000).
 * If the value is invalid, prints an error message with the original line.
 * Returns true if the value is valid, false otherwise.
 */
bool	BitcoinExchange::isValidValue(const std::string& inputValue, const std::string& line) const {

	std::string tmp = inputValue;
	if (!tmp.empty() && tmp.back() == 'f')
		tmp.pop_back();

	try {
		size_t	idx;
		float	value = std::stof(tmp, &idx);

		if (idx != tmp.length()) {
			std::cout << "Error: bad input => " << line << std::endl;
			return (false);
		}
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			return (false);
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			return (false);
		}
		return (true);
	}
	catch (...) {
		std::cout << "Error: bad input => " << line << std::endl;
		return (false);
	}
}