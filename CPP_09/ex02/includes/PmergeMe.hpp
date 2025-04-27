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
#include <exception>
#include <vector>
#include <deque>
#include <sstream>	 // for std::istringstream

/**
 * A class that performs Ford-Johnson Merge-Insertion Sort (PmergeMe) 
 * on input sequences using both std::vector and std::deque.
 * 		  
 * Handles input parsing, sorting using sequence containers, and timing.
 * Containers:
 * - Vector: Dynamic array with contiguous storage.
 * - Deque: Double-ended queue supporting fast insertions/removals at both ends.
 */

class	PmergeMe {

	private:
		// Input storage and working containers
		std::vector<int>	_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		// Timing
		double				_elapsedTimeVector;
		double				_elapsedTimeDeque;
		
		void	mergeInsertionSortVector(std::vector<int>& container);
		void	mergeInsertionSortDeque(std::deque<int>& container);
		
		std::vector<size_t> generateJacobsthalNumbers(size_t limit);
		std::vector<size_t> generateOptimalInsertOrder(size_t bSize);
		
		template <typename C>
			void	importData(C& container, int argc, char **argv);
		
		template <typename T>
			void	binaryInsertion(T& container, int n);
		
		template <typename C>
			void	printElements(C& container);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &other);

		void	saveData(int argc, char **argv);
		void	runAlgorithmVectorContainer(int argc, char **argv);
		void	runAlgorithmDequeContainer(int argc, char **argv);
		void	displayInformations(void);
};

#endif
