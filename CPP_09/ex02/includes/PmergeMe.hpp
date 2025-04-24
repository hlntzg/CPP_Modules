/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:45:08 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/24 17:17:02 by hutzig           ###   ########.fr       */
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

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<int>&	getInput() { return(_input); }
		std::vector<int>&	getVector();
		std::deque<int>&	getDeque();
	
		double				getVectorTime() const { return(_elapsedTimeVector); }
		double				getDequeTime() const { return(_elapsedTimeDeque); }

		template <typename Container>
			void run(Container& container,/* char	**argv, */ContainerType type) {
				auto start = std::chrono::high_resolution_clock::now();
				container.clear();
				container.insert(container.end(), getInput().begin(), getInput().end());
		//importData(container, argv);
				//mergeInsertSort(container);  // Ford-Johnson sort implementation (not yet)
				std::this_thread::sleep_for(std::chrono::milliseconds(200));

				auto end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double, std::micro> duration = end - start;
				
				if (type == VECTOR)
						_elapsedTimeVector = duration.count();
				if (type == DEQUE)
						_elapsedTimeDeque = duration.count();
				//std::cout << "After:\t";
				//printElements(container);
				//std::cout << "Time to process a range of " << container.size()
				//	<< " elements with " << containerName << " : "
				//	<< duration.count() << " us" << std::endl;
			}

		template <typename Container>
			void	importData(Container& container, char **argv) {
				
				int		n;
				char	rest;

				while (*argv) {
					std::istringstream	token(*argv);
					if (!(token >> n) || token >> rest || n < 0)
						throw std::runtime_error("Error: All inputs must be positive integers.");
					container.push_back(n);
					argv++;
				}
			}
			
		template <typename Container>
			void	printElements(Container& container) {

				for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
					std::cout << *it << " ";
				std::cout << std::endl;
			}
		
};

#endif
