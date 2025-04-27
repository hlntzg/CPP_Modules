/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:59:03 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/23 08:24:40 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Default constructor for RPN class.
RPN::RPN(void) {}

// Copy constructor
RPN::RPN(const RPN &other) : _stack(other._stack) {}

// Destructor
RPN::~RPN(void) {}

// Assignment operator
RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return (*this);
}

/** 
 * Processes the input string representing a mathematical expression.
 * Tokenizes the string and processes each token (operand or operator).
 * If the expression is invalid, throw an exception. 
 * */
void	RPN::processInput(const std::string &input) {

	if (input.empty())
		throw std::runtime_error("Error: Empty mathematical expression.");

	std::istringstream iss(input);
	std::string token;
	const std::string operators = "+-*/";

	while (std::getline(iss, token, ' ')) {
		
		if (token.empty()) 
			continue ; // If multiple spaces are not allow: throw std::runtime_error("Error: Invalid expression format for RPN.");
		else if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(std::stoi(token));
		else if (token.length() == 1 && operators.find(token) != std::string::npos)
			performOperation(token[0]);
		else
			throw std::runtime_error("Error");
	}
}		

/**
 * Performs a mathematical operation based on the operator token ('+', '-', '*', '/').
 * If there are not enough operands or if division by zero is attempted, throw an exception.
 */
void	RPN::performOperation(char token) {

	if (_stack.size() < 2)
		throw std::runtime_error("Error: Insufficient operands for operator '" + std::string(1, token) + "'.");

	int right = _stack.top(); _stack.pop();
	int left = _stack.top(); _stack.pop();
	switch (token) {
		case '+': _stack.push(left + right); break;
		case '-': _stack.push(left - right); break;
		case '*': _stack.push(left * right); break;
		case '/': 
			if (right == 0)
				throw std::runtime_error("Error: Division by zero is not allowed.");
			_stack.push(left / right); break;
		default:
			throw std::runtime_error("Error: Invalid operator format.");
	}
}

/**
 * Display the final result of the RPN calculation.
 * If the stack does not contain exactly one element after processing, throw an exception.
 */
void	RPN::getResult() {

	if ( _stack.empty() || _stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression format for RPN.");
	std::cout << _stack.top() << std::endl;
}	
