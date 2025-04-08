/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:15:20 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/08 11:11:58 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>

enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

/**
 * The class acts as a utility class with one static methods only.
 * It is non-instantiable and its design prevents copying since constructor 
 * and basic functions from Orthodox Canonical Form are deleted.
 */
class	ScalarConverter {

	private:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		~ScalarConverter(void) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;

	public:
		static void	convert(const std::string &str);
};

#endif
