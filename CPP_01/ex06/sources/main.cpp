/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:29:46 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:29:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr	<< std::endl << "Error: Incorrect number of arguments.\n"
					<< "Usage: ./harlFilter <level>\n"
					<< "Levels: DEBUG; INFO; WARNING; ERROR;\n"
					<< std::endl;
		return (1);
	}
	
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
