/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:42:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/09 15:56:38 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr	<< "Error: Invalid number of arguments." << std::endl
					<< "Usage: ./ScalarConverter <string> " << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);

	return (0);
}
