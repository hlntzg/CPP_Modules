/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:36:34 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/14 13:48:41 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void){
	PhoneBook	phonebook;
	std::string	input;
	
	std::cout	<< std::endl
				<< " ˗ˏˋ WELCOME TO MY AWESOME PHONEBOOK ´ˎ˗ " << std::endl
				<< "-----------------------------------------" << std::endl
				<< std::endl;

	while (1) {
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Please enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			std::cout << "Exiting program." << std::endl;
			break ;
		}
		else if (input == "ADD") {
			phonebook.addContact();
			if (std::cin.eof()) {
				 std::cout << "EOF encountered. Exiting program." << std::endl;
				 break;
			}
		}
		else if (input == "SEARCH") {
			phonebook.searchContact();
			if (std::cin.eof()) {
				 std::cout << "EOF encountered. Exiting program." << std::endl;
				 break;
			}
		}
		else if (std::cin.eof()) {
			std::cout << "EOF encountered. Exiting program." << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return (0);
}
