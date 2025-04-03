/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:44:17 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/03 15:08:35 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>

class	Bureaucrat;

class	AForm {
	
	private:
		const std::string	_name;
		bool				_signedForm;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, unsigned int signGrade, unsigned int executeGrade);
		AForm(const AForm &other);
		virtual ~AForm(void);
		AForm &operator=(const AForm &other);

		std::string		getName(void) const;
		bool			getSignedForm(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;

		void			beSigned(const Bureaucrat &b);
		
		virtual void	execute(Bureaucrat const &executor) const = 0;	// Pure virtual function
	
		class	GradeTooHighException : public std::exception {
			
			public:
				virtual const char* what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception {

			public:
				virtual const char* what() const noexcept override; 
		};
		
		class	FormNotSignedException : public std::exception {

			public:
                virtual const char* what() const noexcept override;
        };
};

std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif
