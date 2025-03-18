/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:47:54 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/17 12:28:57 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // std::
#include <string>	 // std::string
#include <cctype>    // std::toupper

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv){

	if (argc == 1){
		std::cout << DEFAULT << std::endl;
		return (0);
	}
   for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); ++j) {
            arg[j] = std::toupper(arg[j]);
        }
        std::cout << arg;
    }
	std::cout << std::endl;
	return (0);
}
