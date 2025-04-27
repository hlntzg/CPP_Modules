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

void	PmergeMe::runAlgorithmVectorContainer(int argc, char **argv) {

		auto start = std::chrono::high_resolution_clock::now();
		importData(_vector, argc, argv + 1);
		mergeInsertSort(_vector);  // Ford-Johnson sort implementation
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> duration = end - start;
        
		_elapsedTimeVector = duration.count();
}

void	PmergeMe::runAlgorithmDequeContainer(int argc, char **argv) {
	
		auto start = std::chrono::high_resolution_clock::now();
		importData(_deque, argc, argv + 1);
		mergeInsertSort(_deque);  // Ford-Johnson sort implementation
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> duration = end - start;

		_elapsedTimeDeque = duration.count();
}

void	PmergeMe::displayInformations(void) {
		
		std::cout << "Before:\t";
		printElements(_input);

		std::cout << "After:\t";
		printElements(_vector);

		std::cout << "Time to process a range of " << _vector.size()
				  << " elements with std::vector : " << _elapsedTimeVector<< " us" << std::endl;

		std::cout << "Time to process a range of " << _deque.size()
				  << " elements with std::deque  : " << _elapsedTimeDeque << " us" << std::endl;

}


// Template function to perform binary insertion into a sorted container
template <typename T>
void PmergeMe::binaryInsertion(T& container, int num) {
    int left = 0;                // Start of the container
    int right = container.size(); // End of the container (exclusive)

    // Binary search to find the correct position for num
    while (left < right) {
        int mid = left + (right - left) / 2; // Find the middle position
        if (num < container[mid]) {
            right = mid;  // Narrow the search to the left half
        } else {
            left = mid + 1; // Narrow the search to the right half
        }
    }

    // Insert num at the position found by binary search (at index `left`)
    container.insert(container.begin() + left, num);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container) {
	
	int size = container.size();
	if (container.size() < 2)
		return ;
	
	// 1#	Pair elements and store them into group A (bigger values) and B (smaller values) by comparing elements in pairs.
	std::vector<std::pair<int, int>> pairs;
	for (int i = 0; i < size - 1; i += 2) 
	{
		int first = container[i];
		int second = container[i + 1];
		if (first < second)
			pairs.emplace_back(second, first);
		else
			pairs.emplace_back(first, second);
	}
	
	T A, B;
	for (const auto& p : pairs) {
		A.push_back(p.first);
		B.push_back(p.second);
	}
	if (size % 2 == 1)
		A.push_back(container.back());

	// 2#	Recursively sort the group A
	mergeInsertSort(A);

	// 3#	Define the order elements of B should be insert into A
	std::vector<size_t> insertOrder = generateOptimalInsertOrder(B.size());

	// 4#	Insert elements of group B into the sorted group A
	for (size_t index : insertOrder)  { //For each index in the insertOrder…
		if (index < B.size()) {
			binaryInsertion(A, B[index]);
		}
	}

	container = A;
}