/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:58:29 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/23 08:28:42 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream> // For std::istringstream
#include <string>
#include <stack>

/**
 * Operand: The value on which an operator is performed
 * Operator: A symbol related to a mathematical operation
 */

class	RPN {
	
	private:
		std::stack<int>	_stack;

	public:
		RPN(void);
		RPN(const RPN &other);
		~RPN(void);
		RPN &operator=(const RPN &other);
		
		void	processInput(const std::string &input);
		void	performOperation(char token);
		void	getResult();
};

#endif
