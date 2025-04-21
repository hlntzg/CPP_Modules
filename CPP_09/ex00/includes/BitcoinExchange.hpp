/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:09:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/21 12:08:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>


class	BitcoinExchange {
	
	private:
		std::map<std::string, float>	_database;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	importDatabase(const std::string& database);
		void	processFile(const std::string& filename);

};

#endif
