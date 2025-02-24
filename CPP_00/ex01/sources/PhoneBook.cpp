/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:47:38 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/24 18:46:03 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() : _index(0), _count(0) {}

// Destructor
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(void)
{
   try {
        _contacts[_index % 8].setContact();
        if (_count < 8) {
            _count++;
        } else {
            std::cout << "PhoneBook is full. Oldest contact replaced." << std::endl;
        }
        _index++;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void	PhoneBook::searchContact(void)
{
	if (_count == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

	for (int i = 0; i < _count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
    }

	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);

	try {
		int index = std::stoi(input);
		if (index < 0 || index >= _count) {
			throw std::out_of_range("Invalid index!");
		}
		_contacts[index].displayContact();
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

std::string PhoneBook::truncate(const std::string &str)
{
    if (str.length() > 10) {
        return (str.substr(0, 9) + ".");
    }
    return (str);
}
