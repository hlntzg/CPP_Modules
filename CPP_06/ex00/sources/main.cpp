/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:42:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/08 09:56:03 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		str::err	<< "Error: Invalid number of arguments." << std::endl
					<< "Usage: ./ScalarConverter <string> " << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}
