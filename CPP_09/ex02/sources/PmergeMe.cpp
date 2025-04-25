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


// Jacobsthal Sequence J(n) = J(n-1) + 2 × J(n-2)
// Returns a vector that contains the numbers from Jacobsthal sequence ({0, 1, 3, 5, ...}) less than or equal to the limit (B.size())
std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t limit) {
	std::vector<size_t> sequence = {0, 1};
	while (sequence.back() < limit) {
		sequence.push_back(sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2]);
	}
	return (sequence);
}

// returns a sequence of indices!!
// Returns a full permutation of [0, ..., bSize - 1] representing the order 
// in which you should insert elements from B into A
std::vector<size_t> PmergeMe::generateOptimalInsertOrder(size_t bSize) {

	std::vector<size_t> jcbs = generateJacobsthalNumbers(bSize);

	std::vector<size_t>	insertOrder;
	std::vector<bool> 	used(bSize, false);
	// Skip J(0) = 0 to avoid biasing the first insertion (more balanced insert pattern)
	for (size_t i = 1; i < jcbs.size(); i++) 
	{
		size_t jcbsN = jcbs[i];
		if (jcbsN < bSize && !used[jcbsN]) {
			insertOrder.push_back(jcbsN);
			used[jcbsN] = true;
		}
	}

	// Fill in remaining indices in increasing order (0 to bSize - 1)
	for (size_t i = 0; i < bSize; i++) {
		if (!used[i]) 
			insertOrder.push_back(i);
	}

	return (insertOrder);
}