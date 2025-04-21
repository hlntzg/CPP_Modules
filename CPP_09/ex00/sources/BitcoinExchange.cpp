/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:11:01 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/21 14:13:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_database = other._database;
	}
	return (*this);
}

void	BitcoinExchange::importDatabase(const std::string& database) {

	if (database.size() < 4 || database.substr(database.size() - 4) != ".csv")
		throw std::invalid_argument("Error: Invalid file extension. Expected a '.csv' file.");

	std::ifstream	file(database);
	if (!file.is_open())
		throw std::runtime_error("Error: Failure to open '" + database + "'");
	if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: File '" + filename + "' is empty");

	std::string		line;
	bool			databaseHeader = true;

	while (std::getline(database, line)) {
		if (databaseHeader) {
			databaseHeader = false;
			continue;
		}
		try {

		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	

    database.close();
}



bool	BitcoinExchange::isValidDate(const std::string& inputDate, std::string line) {

    /*std::regex	dataPattern(R"((\d{4})-(\d{2})-(\d{2}))");
    std::smatch match;

    if (!std::regex_match(inputDate, match, format))
        return (false);
	*/
	int	year, month, day;
    try {
        year = std::stoi(inputDate.substr(0, 4));//std::stoi(match[1]);
        month = std::stoi(inputDate.substr(5, 2));//std::stoi(match[2]);
        day = std::stoi(inputDate.substr(8, 2));//std::stoi(match[3]);
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

bool	BitcoinExchange::isValidValue(const std::string& inputValue, std::string line) {

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

/*{
	if (inputValue.back() == 'f')
        inputValue.pop_back();

    std::stringstream	ssObj(inputValue);
    float				floatValue;
    ssObj >> floatValue;

	if (!ssObj.eof()){
		std::cout << "Error: bad input " << line << std::endl;
		return (false);
	}
	if (ssObj.fail() && ssObj.eof()){
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	if (floatValue < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (floatValue > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}*/

void	BitcoinExchange::processFile(const std::string& filename) {

	std::ifstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("Error: Failure to open '" + filename + "'");
	if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: File '" + filename + "' is empty");
	
	std::string	line;
	bool headerLine = true;
    const std::regex pattern(R"(^\s*(\d{4}-\d{2}-\d{2})\s*\|\s*(-?\d+(\.\d+)?)\s*$)"); // Regex pattern with strict validation

	while (std::getline(file, line)) {	
		if (line.empty())
            continue;

		if (headerLine) {
			headerLine = false;
			if (line == "date | value") 
				continue;
		}
        
		std::smatch sm;
        if (!std::regex_match(line, sm, pattern)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
		
		std::string inputDate = sm[1].str();
		std::string inputValue = sm[2].str();

		if (!isValidDate(inputDate, line) || !isValidValue(inputValue, line))
			continue; 

		// Lookup rate and print result
		try {
			float	value = std::stof(inputValue);
			float	rate = findClosestValue(inputDate);
			float	result = rate * value;
			std::cout << inputDate << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	file.close();
}
