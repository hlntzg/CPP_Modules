/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:47:54 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/22 16:47:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // std::
#include <string>	 // std::string
#include <algorithm> // std::transform
#include <cctype>    // std::toupper

const std::string DEFAULT = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

int	main(int argc, char **argv){

	if (argc == 1){
		std::cout << DEFAULT << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i){
		std::string	arg = argv[i];
		std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
		std::cout << arg;
		}
	std::cout << std::endl;
	return (0);
}
