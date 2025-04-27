/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:09:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/21 16:30:23 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>	// for std::ifstream
#include <string>
#include <regex> 	// for std::regex
#include <map>
#include <exception> 

class	BitcoinExchange {
	
	private:
		// Database of exchange rates
		std::map<std::string, float>	_database;
		
		bool	isValidDate(const std::string& inputDate, const std::string& line) const;
		bool	isValidValue(const std::string& inputValue, const std::string& line) const;
		bool	isLeapYear(int year) const;
		float	findDatabaseValue(const std::string& inputDate);
	
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	importDatabase(const std::string& database);
		void	processFile(const std::string& filename);
};

#endif
