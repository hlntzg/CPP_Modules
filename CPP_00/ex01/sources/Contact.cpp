/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:48:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/22 20:22:10 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Conctat::Contact(void){}

Conctat::~Contact(void){}

void	Contact::setFirstName(std::string firstName)
{
    if (firstName.empty())
		throw std::invalid_argument("Empty first name.");
	for (std::size_t i = 0; i < firstName.length(); i++){
		if (!std::isalpha(firstName[i])
			throw std::invalid_argument("Invalid first name.");
	}
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
    if (lastName.empty())
		throw std::invalid_argument("Empty last name.");
	for (std::size_t i = 0; i < lastName.length(); i++){
		if (!std::isalpha(lastName[i])
			throw std::invalid_argument("Invalid last name.");
	}
	_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
    if (nickname.empty())
		throw std::invalid_argument("Empty nickname.");
	for (std::size_t i = 0; i < nickname.length(); i++){
		if (!std::isalnum(nickname[i] && nickname[i] != '_' && nickname[i] != '-' && nickname[i] != '.')
			throw std::invalid_argument("Invalid nickname.");
	}
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.empty())
		throw std::invalid_argument("Empty phone number.");
	for (std::size_t i = 0; i < phoneNumber.length(); i++){
		if (!std::isdigit(phoneNumber[i])
			throw std::invalid_argument("Invalid phone number.");
	}
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string daskestSecret)
{
    if (darkestSecret.empty())
		throw std::invalid_argument("Empty darkest secret.");
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(void) { return (_firstName); }
std::string	Contact::getLastName(void) { return (_lastName); }
std::string	Contact::getNickname(void) { return (_nickname); }
std::string	Contact::getPhoneNumber(void) { return (_phoneNumber); }
std::string	Contact::getDarkestSecret(void) { return (_darkestSecret); }

void Contact::setContact()
{
    const std::string prompts[] = {
        "\tEnter first name: ", "\tEnter last name: ", 
        "\tEnter nickname: ", "\tEnter phone number: ", 
        "\tEnter darkest secret: "
    };

    void (Contact::*setters[])(const std::string) = {
        &Contact::setFirstName, &Contact::setLastName,
        &Contact::setNickname, &Contact::setPhoneNumber,
        &Contact::setDarkestSecret
    };

    std::string input;
    for (int i = 0; i < 5; i++) {
        bool valid = false;
        for (int attempts = 0; attempts < 3 && !valid; attempts++) {
            std::cout << prompts[i];
            std::getline(std::cin, input);
            try {
                (this->*setters[i])(input);
                valid = true;
            } catch (const std::exception& e) {
                std::cout << "Invalid input. Please try again." << std::endl;
            }
        }
        if (!valid) {
            std::cout << "Failed to set contact. Operation canceled." << std::endl;
            return ;
        }
    }
    std::cout << "Contact added successfully!" << std::endl;
}

void	Contact::displayContact(void)
{
	std::cout << "First name:\t" << _firstName << std::endl;
	std::cout << "Last name:\t" << _lastName << std::endl;
	std::cout << "Nickname:\t" << _nickname << std::endl;
	std::cout << "Phone number:\t" << _phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << _darkestSecret << std::endl;
}
