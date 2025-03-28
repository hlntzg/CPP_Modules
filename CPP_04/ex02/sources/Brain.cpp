/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:11:41 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 15:18:25 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Default idea";
	std::cout	<< "[ Brain ] Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout	<< "[ Brain ] Copy constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout	<< "[ Brain] Default destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout	<< "[ Brain ] Copy assigment operator called" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int i) const {
	return ((i >= 0 && i < 100) ? _ideas[i] : "No idea!");
}

void		Brain::setIdea(int i, const std::string& newidea) {
	if (i >= 0 && i < 100)
		_ideas[i] = newidea;
	return ;
}
