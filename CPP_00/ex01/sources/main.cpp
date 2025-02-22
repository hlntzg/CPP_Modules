/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:36:34 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/22 17:04:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "My Awesome PhoneBook: Welcome!" << std::endl;
	
	while (1) {
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Please enter a command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT" || std::cin.eof()) {
			std::cout << "Exiting program.!" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
