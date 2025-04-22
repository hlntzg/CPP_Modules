/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:59:03 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/22 12:04:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

void	RPN::processInput(const std::string &input) {

	if (input.empty())
		throw std::runtime_error("Error: Empty mathematical expression.");

	std::istringstream iss(input);
	std::string token;
	const std::string operators = "+-*/";

	while (std::getline(iss, token, ' ')) {

		if (token.empty()) 
			throw std::runtime_error("Error: Invalid expression format for RPN.");
		else if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(std::stoi(token));
		else if (token.length() == 1 && operators.find(token) != std::string::npos)
			performOperation(token[0]);
		else
			throw std::runtime_error("Error");
			//throw std::runtime_error("Error: Invalid token '" + token + "'");
	}
}		

void	RPN::performOperation(char token) {

	if (_stack.size() < 2)
		throw std::runtime_error(std::string("Error: operator '") + token + "' missing operands");

	int right = _stack.top(); _stack.pop();
	int left = _stack.top(); _stack.pop();
	switch (token) {
		case '+': _stack.push(left + right); break;
		case '-': _stack.push(left - right); break;
		case '*': _stack.push(left * right); break;
		case '/': 
			if (right == 0)
				throw std::runtime_error("Error: Attempted to divide by Zero.");
			_stack.push(left / right); break;
		default:
			throw std::runtime_error("Error: Invalid operator format.");
	}
}

void	RPN::getResult() {

	if (_stack.size() != 1 || _stack.empty())
		throw std::runtime_error("Error: Invalid expression format for RPN.");
	
	std::cout << _stack.top() << std::endl;
}	
