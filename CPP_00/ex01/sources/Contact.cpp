/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:48:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/14 15:28:16 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

void	Contact::setFirstName(std::string firstName)
{
    if (firstName.empty())
		throw std::invalid_argument("Empty first name.");
	for (std::size_t i = 0; i < firstName.length(); i++){
		if (!std::isalpha(firstName[i]))
			throw std::invalid_argument("Invalid first name.");
	}
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
    if (lastName.empty())
		throw std::invalid_argument("Empty last name.");
	for (std::size_t i = 0; i < lastName.length(); i++){
		if (!std::isalpha(lastName[i]))
			throw std::invalid_argument("Invalid last name.");
	}
	_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
    if (nickname.empty())
		throw std::invalid_argument("Empty nickname.");
	for (std::size_t i = 0; i < nickname.length(); i++){
		if (!(std::isalnum(nickname[i]) || nickname[i] == '_' || nickname[i] == '-' || nickname[i] == '.'))
			throw std::invalid_argument("Invalid nickname.");
	}
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.empty())
		throw std::invalid_argument("Empty phone number.");
	for (std::size_t i = 0; i < phoneNumber.length(); i++){
		if (!std::isdigit(phoneNumber[i]))
			throw std::invalid_argument("Invalid phone number.");
	}
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
    if (darkestSecret.empty())
		throw std::invalid_argument("Empty darkest secret.");
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(void) const { return (_firstName); }
std::string	Contact::getLastName(void) const { return (_lastName); }
std::string	Contact::getNickname(void) const { return (_nickname); }
std::string	Contact::getPhoneNumber(void) const { return (_phoneNumber); }
std::string	Contact::getDarkestSecret(void) const { return (_darkestSecret); }

bool Contact::setContact()
{
    const std::string prompts[] = {
        "\tEnter first name: ",
		"\tEnter last name: ", 
        "\tEnter nickname: ",
		"\tEnter phone number: ", 
        "\tEnter darkest secret: "
    };

    void (Contact::*setters[])(const std::string) = {
        &Contact::setFirstName,
		&Contact::setLastName,
        &Contact::setNickname,
		&Contact::setPhoneNumber,
        &Contact::setDarkestSecret
    };

    std::string input;
    for (int i = 0; i < 5; i++) {
        bool valid = false;
        for (int attempts = 0; attempts < 3 && !valid; attempts++) {
            std::cout << prompts[i];
            std::getline(std::cin, input);

			if (std::cin.eof() || input == "CANCEL")
				return (false);
            
			try {
                (this->*setters[i])(input);
                valid = true;
            } catch (const std::exception& e) {
			    std::cout << "Error: " << e.what() << " Please try again." << std::endl;
            }
        }
        if (!valid) {
            std::cout << "Failed to set contact. Operation canceled." << std::endl;
            return (false);
        }
    }
	return (true);
}

void	Contact::displayContact(void)
{
    std::cout << "-------------------------------------------" << std::endl;
	std::cout << "\tFirst name:\t" << _firstName << std::endl;
	std::cout << "\tLast name:\t" << _lastName << std::endl;
	std::cout << "\tNickname:\t" << _nickname << std::endl;
	std::cout << "\tPhone number:\t" << _phoneNumber << std::endl;
	std::cout << "\tDarkest secret:\t" << _darkestSecret << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}
