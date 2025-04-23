/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:45:08 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/23 15:52:09 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>

/**
 * Sequence Containers:
 * - Vector: STL vector can be defined as the dynamic sized array which can be resized automatically when new elements are added or removed
 * - Deque (or Double-Ended Queue): Sequence containers with the feature of expansion and contraction on both ends. It means we can add and remove the data to and from both ends.
 */
class	PmergeMe {

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<int>&	getVector();
		std::deque<int>&	getDeque();

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
