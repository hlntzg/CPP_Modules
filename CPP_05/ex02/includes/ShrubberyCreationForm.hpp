/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:45:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/03 15:51:22 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
//#ifndef SHRUBBERYCREATIONFORM_HPP
//# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <fstream>  // for std::ofstream
#include <stdexcept> // for std::runtime_error

//class	Bureaucrat;

class	ShrubberyCreationForm : public AForm {
	
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

		void	execute(Bureaucrat const &executor) const override;
};

//#endif
