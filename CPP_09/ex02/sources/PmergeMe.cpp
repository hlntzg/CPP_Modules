/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:48:40 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/24 18:04:46 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _elapsedTimeVector(0), _elapsedTimeDeque(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _input(other._input), _vector(other._vector), _deque(other._deque), _elapsedTimeVector(other._elapsedTimeVector), _elapsedTimeDeque(other._elapsedTimeDeque) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_input = other._input;
		_vector = other._vector;
		_deque = other._deque;
		_elapsedTimeVector = other._elapsedTimeVector;
		_elapsedTimeDeque = other._elapsedTimeDeque;
	}
	return (*this);
}

std::vector<int>&	PmergeMe::getInput() { return _input; }
std::vector<int>&	PmergeMe::getVector() { return _vector; }
std::deque<int>&	PmergeMe::getDeque() { return _deque; }
double				PmergeMe::getVectorTime() const { return _elapsedTimeVector; }
double				PmergeMe::getDequeTime() const { return _elapsedTimeDeque; }

/*
template <typename Container>
void	PmergeMe::mergeInsertSort(Container& container) {

	std::cout << "Hi from merge insert sort!" << std::endl;
	printElements(container);
}*/
