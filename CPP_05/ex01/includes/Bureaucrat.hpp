/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:11:06 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 15:01:05 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp" // function implementations require functions from Form.hpp

#include <iostream>
#include <string>
#include <exception>  // for std::exception

class	Form;

class	Bureaucrat {

	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &other);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void			incrementGrade();
		void			decrementGrade();

		void			signForm(Form &f); // additional member function

		class	GradeTooHighException : public std::exception {
			
			public:
				virtual const char* what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const noexcept override; 
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);	// insertion overload («) operator

#endif
