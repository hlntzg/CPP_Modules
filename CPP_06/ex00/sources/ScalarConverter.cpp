/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:40:05 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 10:46:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>    // For std::string
#include <cctype>    // For std::isprint, std::isdigit
#include <sstream>   // For std::stringstream
#include <limits>	 // 
#include <cctype>
#include <iomanip>   // For std::setprecision

/**
 * _isChar: The function checks if the string length is exactly 1, ensures the
 * character is printable (ASCII values from 32 - 126) and it is not a digit.
 */
static bool	_isChar(const std::string &str) {
	return (str.length() == 1 /*&& std::isprint(str[0])*/ && !std::isdigit(str[0]));	
}

/**
 * _isInt: The function uses std::stringstream to attempt parsing the string
 * into an integer. If parsing succeeds and the stream reaches the end of string
 * (ssObj.eof), the function is a valid integer.
 */
static bool	_isInt(const std::string &str) {
    std::stringstream	ssObj(str);
    
	int	value;
    ssObj >> value;
    return (ssObj.eof() && !ssObj.fail());
}

/**
 * _isDouble : The function uses std::stringstream to attempt parsing the string
 * into a double. If parsing succeeds and the stream reaches the end of string
 * (ssObj.eof), the function is a valid double.
 */
static bool	_isDouble(const std::string &str) {
    std::stringstream	ssObj(str);
    
	double	value;
    ssObj >> value;
    return (ssObj.eof() && !ssObj.fail());
}

/**
 * _isFloat: The function creates a temporary string and remove 'f' suffix if present.
 * It attempts to parse the string into a float value.If parsing succeeds and the 
 * stream reaches the end of string (ssObj.eof), the function is a valid float.
 */
static bool	_isFloat(const std::string &str) {
    std::string	tmp = str;
	if (!tmp.empty() && tmp.back() == 'f')
		tmp.pop_back();

	std::stringstream	ssObj(tmp);
    
	float	value;
    ssObj >> value;
    return (ssObj.eof() && !ssObj.fail());

	/*    char* end = nullptr;
    float value = std::strtof(tmp.c_str(), &end);
    // Check if parsing was successful and consumed the entire string
    return end == tmp.c_str() + tmp.size();
	*/
}

static bool	_isPseudoFloat(const std::string &str) {
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	return (false);
}

static bool	_isPseudoDouble(const std::string &str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	return (false);
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
	if (_isPseudoFloat(str))
		return (PSEUDOFLOAT);
	if (_isPseudoDouble(str))
		return (PSEUDODOUBLE);
	return (UNKNOWN);
}

static void	_toChar(const std::string &str, int type) {
	try {
		if (type == CHAR) {
			std::cout << "char: '" << str[0] << "'" << std::endl;
		}
		else if (type == INT) {
			int value = std::stoi(str);
			if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
				if (isprint(static_cast<unsigned char>(value)))
					std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
                std::cout << "char: impossible" << std::endl;
		}
		else if (type == FLOAT || type == DOUBLE) {
			std::string temp = str;
            if (type == FLOAT && temp.back() == 'f')
                temp.pop_back();

            double value = std::stod(temp);
            if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
                if (isprint(static_cast<unsigned char>(value)))
                    std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;
            } 
			else
                std::cout << "char: impossible" << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
    }
}

static void	_toInt(const std::string &str, int type) {
	try {
		if (type == CHAR)
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		else if (type == INT) {
			size_t	idx;
			int		value = std::stoi(str, &idx);
			if (idx != str.size())
				throw std::invalid_argument("invalid characters");
			std::cout << "int: " << value << std::endl;
		}
		else if (type == FLOAT || type == DOUBLE) {
			std::string	temp = str;
			if (type == FLOAT && temp.back() == 'f')
				temp.pop_back();

			double value = std::stod(temp);
			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) 
				std::cout << "int: " << static_cast<int>(value) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
		}
		else
			std::cout << "int: impossible" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "int: impossible" << std::endl;
	}
}

static void	_toFloat(const std::string &str, int type) {
	try {
		if (type == CHAR)
			std::cout << "float: " << static_cast<float>(str[0]) << ".0f" <<std::endl;
		else if (type == INT) {
			size_t idx;
			float value = std::stof(str, &idx);
			if (idx != str.size()) {
				throw std::invalid_argument("invalid characters");
			}
			std::cout << "float: " << static_cast<int>(value) << ".0f" << std::endl;
		}
		else if (type == FLOAT || type == DOUBLE) {
			std::string temp = str;
			if (type == FLOAT && temp.back() == 'f')
				temp.pop_back();

			float value = static_cast<float>(std::stod(temp));
			std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
}

static void	_toDouble(const std::string &str, int type) {
	try {
		if (type == CHAR)
			std::cout << "double: " << static_cast<double>(str[0]) << ".0" <<std::endl;
		else if (type == INT) {
			size_t idx;
			double value = std::stod(str, &idx);
			if (idx != str.size()) {
				throw std::invalid_argument("invalid characters");
			}
			std::cout << "double: " << static_cast<int>(value) << ".0" << std::endl;
		}
		else if (type == FLOAT || type == DOUBLE) {
			std::string temp = str;
			if (type == FLOAT && temp.back() == 'f')
				temp.pop_back();

			double value = std::stod(temp);
			std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		}
		else
			std::cout << "double: impossible" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
}

static void	_typeConversionImpossible(void) {
	std::cout	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
}

static void	_toPseudoFloat(const std::string &str) {
	std::cout	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: " << str << std::endl
				<< "double: " << str.substr(0, str.length() - 1) << std::endl;
}
static void	_toPseudoDouble(const std::string &str) {
	std::cout	<< "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: " << str << "f" << std::endl
				<< "double: " << str << std::endl;
}

void	ScalarConverter::convert(const std::string &str) {
	if (str.empty()) {
		std::cout	<< "Error: Invalid argument: empty string." << std::endl;
		return ;
	}
	try {
		int	type = getType(str);
		switch (type)
		{
			case CHAR:
				_toChar(str, type);
				_toInt(str, type);
				_toFloat(str, type);
				_toDouble(str, type);
				break ;
			case INT:
				_toChar(str, type);
				_toInt(str, type);
				_toFloat(str, type);
				_toDouble(str, type);
				break ;
			case FLOAT:
				printf("in float case\n");
				_toChar(str, type);
				_toInt(str, type);
				_toFloat(str, type);
				_toDouble(str, type);
				break ;
			case DOUBLE:
				printf("in double case\n");
				_toChar(str, type);
				_toInt(str, type);
				_toFloat(str, type);
				_toDouble(str, type);
				break ;
			case PSEUDOFLOAT:
				_toPseudoFloat(str);
				break ;
			case PSEUDODOUBLE:
				_toPseudoDouble(str);
				break ;
			case UNKNOWN:
				_typeConversionImpossible();
				break ;
			default:
				break ;
//				throw InvalidStringLiteralException();
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
