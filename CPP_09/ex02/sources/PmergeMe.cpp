/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:48:40 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/23 15:31:20 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

std::vector<int>&	PmergeMe::getVector() { return _vector; }

std::deque<int>&	PmergeMe::getDeque() { return _deque; }

