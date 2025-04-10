/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:42:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/10 17:11:43 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define COLOR "\033[0;35m"
#define RESET "\033[0;0m"
#if 0
int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr	<< "Error: Invalid number of arguments." << std::endl
					<< "Usage: ./ScalarConverter <string> " << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}
#endif

#if 1
static void	testInvalid();
static void	testChar();
static void testInteger();
static void	testFloat();
static void	testDouble();

int	main(void) {

	testInvalid();
	testChar();
	testInteger();
	testFloat();
	testDouble();

	return (0);
}

static void	testInvalid() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid string representation ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '❤' ]" << RESET << std::endl;
	ScalarConverter::convert("❤");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'abc' ]" << RESET << std::endl;
	ScalarConverter::convert("abc");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '\\t' ]" << RESET << std::endl;
	ScalarConverter::convert("'\t'");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '' '' ]" << RESET << std::endl;
	ScalarConverter::convert("' '");
}

static void	testChar() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Char ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'a' ]" << RESET << std::endl;
	ScalarConverter::convert("a");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '\t' ]" << RESET << std::endl;
	ScalarConverter::convert("\t");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: ' ' ]" << RESET << std::endl;
	ScalarConverter::convert(" ");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'Z' ]" << RESET << std::endl;
	ScalarConverter::convert("Z");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '*' ]" << RESET << std::endl;
	ScalarConverter::convert("*");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+' ]" << RESET << std::endl;
	ScalarConverter::convert("+");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '/' ]" << RESET << std::endl;
	ScalarConverter::convert("/");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '@' ]" << RESET << std::endl;
	ScalarConverter::convert("@");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '?' ]" << RESET << std::endl;
	ScalarConverter::convert("?");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '0': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '9': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '木': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("木");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'ã': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("ã");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '€': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("€");
}

static void testInteger() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Integer ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1' ]" << RESET << std::endl;
	ScalarConverter::convert("1");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-2' ]" << RESET << std::endl;
	ScalarConverter::convert("-2");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '2222' ]" << RESET << std::endl;
	ScalarConverter::convert("2222");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+42' ]" << RESET << std::endl;
	ScalarConverter::convert("+42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-42' ]" << RESET << std::endl;
	ScalarConverter::convert("-42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '2147483647' ]" << RESET << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-2147483648' ]" << RESET << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+2147483648': Overflow ]" << RESET << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-2147483649': Overflow ]" << RESET << std::endl;
	ScalarConverter::convert("-2147483649");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '++1234': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("++1234");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-1234abc': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("-1234abc");
	std::cout	<< COLOR <<  "[ Input: '+1234a': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("+1234a");
}
static void	testFloat() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Float ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '0.0f' ]" << RESET << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-0.5f' ]" << RESET << std::endl;
	ScalarConverter::convert("-0.5f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '42.0f' ]" << RESET << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1234.5' ]" << RESET << std::endl;
	ScalarConverter::convert("1234.5");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1234.5f' ]" << RESET << std::endl;
	ScalarConverter::convert("1234.5f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-42.42' ]" << RESET << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-inff' ]" << RESET << std::endl;
	ScalarConverter::convert("-inff");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+inff' ]" << RESET << std::endl;
	ScalarConverter::convert("+inff");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'nanf' ]" << RESET << std::endl;
	ScalarConverter::convert("nanf");
	std::cout	<< "-----------------------------------------" << std::endl;
}
static void	testDouble() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Double ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-inf' ]" << RESET << std::endl;
	ScalarConverter::convert("-inf");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+inf' ]" << RESET << std::endl;
	ScalarConverter::convert("+inf");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'nanf' ]" << RESET << std::endl;
	ScalarConverter::convert("nan");
	std::cout	<< "-----------------------------------------" << std::endl;
}


#endif
