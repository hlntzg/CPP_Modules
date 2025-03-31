/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:37:54 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 16:19:59 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class	Form {
	
	private:
		const std::string	_name;
		bool				_signedForm;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		Form(void);
		Form(const std::string name, unsigned int signGrade, unsigned int executeGrade);
		Form(const Form &other);
		~Form(void);
		Form &operator=(const Form &other);

		std::string		getName(void) const;
		bool			getSignedForm(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;

		void			beSigned(const Bureaucrat &b);
		
		class	GradeTooHighException : public std::exception {
			
			public:
				virtual const char* what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const noexcept override; 
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &f);	// insertion overload («) operator 

#endif
