/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:55:28 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 14:15:51 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <exception>  // for std::exception

class	Intern {

	public:
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);
		Intern &operator=(const Intern &other);

		AForm*	makeForm(const std::string &name, const std::string &target); 

		static AForm*	makeShrubberyForm(const std::string &target);
		static AForm*	makeRobotomyForm(const std::string &target);
		static AForm*	makePresidentialForm(const std::string &target);

		class	FormNotFoundException : public std::exception {

			public:
				virtual const char* what() const noexcept override;
		};
};

#endif
