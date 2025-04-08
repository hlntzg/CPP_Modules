/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:40:05 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/08 11:14:25 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	_isChar(const std::string &str) {
	return str.length() == 1 && std::isalpha(str[0]);	
}

static bool	_isInt(const std::string &str) {

}

static bool	_isFloat(const std::string &str) {

}

static bool	_isDouble(const std::string &str) {

}

static int	getType(const std::string &str) {
	if (_isChar(str))
		return (CHAR);
	if (_isInt(str))
		return (INT);
	if (_isFloat(str))
		return (FLOAT);
	if (_isDouble(str))
		return (DOUBLE);
}

static void	_toChar(const std::string &str) {
	std::cout << "[ Char ] : ";
}


static void	_toInt(const std::string &str) {
	std::cout << "[ Int ] : ";
}

static void	_toFloat(const std::string &str) {
	std::cout << "[ Float ] : ";
}

static void	_toDouble(const std::string &str) {
	std::cout << "[ Double ] : ";
}

void	ScalarConverter::convert(const str::string &str) {
	
	try {
		//if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan") {
		//	handleSpecialCases(str);
		//	return ;
		//}
		int	type = getType(str);
		switch (type)
		{
			case CHAR:
				_toChar(str);
				break ;
			case INT:
				_toInt(str);
				break ;
			case FLOAT:
				_toFloat(str);
				break ;
			case DOUBLE:
				_toDouble(str);
				break ;
			default:
				throw InvalidStringLiteralException();
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
