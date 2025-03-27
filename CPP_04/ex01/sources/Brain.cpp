/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:11:41 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 16:17:02 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.cpp"

Brain::Brain(void) {
	std::cout	<< "[ Brain ] Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	_ideas[100] = other._ideas[100];
	std::cout	<< "[ Brain ] Copy constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout	<< "[ Brain] Default destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		this->_ideas[100] = other._ideas[100];
	}
	std::cout	<< "[ Brain ] Copy assigment operator called" << std::endl;
	return (*this);
}

