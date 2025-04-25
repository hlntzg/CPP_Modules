/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:45:08 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/25 09:12:05 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <chrono>
#include <thread>
/**
 * Sequence Containers:
 * - Vector: STL vector can be defined as the dynamic sized array which can be resized automatically when new elements are added or removed
 * - Deque (or Double-Ended Queue): Sequence containers with the feature of expansion and contraction on both ends. It means we can add and remove the data to and from both ends.
 */

enum ContainerType { VECTOR, DEQUE };

class	PmergeMe {

	private:
		std::vector<int>	_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_elapsedTimeVector;
		double				_elapsedTimeDeque;

		template <typename T>
		void mergeInsertSort(T& container);
		
		template <typename T>
		void binaryInsertion(T& container, int num);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<int>&	getInput();
		std::vector<int>&	getVector();
		std::deque<int>&	getDeque();
	
		double				getVectorTime() const;
		double				getDequeTime() const;

		template <typename C>
		void 	run(C& container, ContainerType type);

		template <typename C>
		void	importData(C& container, char **argv);
			
		template <typename C>
		void	printElements(C& container);
		
		std::vector<size_t> generateJacobsthalNumbers(size_t limit);
		std::vector<size_t> generateOptimalInsertOrder(size_t bSize);

};

#include "PmergeMe.tpp"

#endif
