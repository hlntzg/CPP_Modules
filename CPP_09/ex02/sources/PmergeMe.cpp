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
#include <chrono>

// Constructor: Initializes elapsed times to 0
PmergeMe::PmergeMe(void) : _elapsedTimeVector(0), _elapsedTimeDeque(0) {}

// Copy constructor: Copies all member data from another object
PmergeMe::PmergeMe(const PmergeMe &other) : _input(other._input), 
	_vector(other._vector), _deque(other._deque), 
	_elapsedTimeVector(other._elapsedTimeVector), _elapsedTimeDeque(other._elapsedTimeDeque) {}

// Destructor
PmergeMe::~PmergeMe(void) {}

// Assignment operator: Ensures deep copy
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

// Save input data from command line arguments into _input container
void	PmergeMe::saveData(int argc, char **argv) {
	importData(_input, argc, argv + 1);
}

// Run Ford-Johnson algorithm on vector, measure and store elapsed time in microseconds (μs)
void	PmergeMe::runAlgorithmVectorContainer(int argc, char **argv) {
		
		auto start = std::chrono::high_resolution_clock::now();
		importData(_vector, argc, argv + 1);
		mergeInsertionSortVector(_vector);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro>	duration = end - start;
        
		_elapsedTimeVector = duration.count();
}

// Run Ford-Johnson algorithm on deque, measure and store elapsed time in microseconds (μs)
void	PmergeMe::runAlgorithmDequeContainer(int argc, char **argv) {
	
		auto start = std::chrono::high_resolution_clock::now();
		importData(_deque, argc, argv + 1);
		mergeInsertionSortDeque(_deque);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro>	duration = end - start;

		_elapsedTimeDeque = duration.count();
}

// Display sequence of input elements before, sorted elements, and processing times by each container
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

/**
 * Template function: importData()
 * - Process command line arguments
 * - Import positive integers into the given container
 */
template <typename C>
void	PmergeMe::importData(C& container, int argc, char **argv) {
	if (argc < 2)
		throw std::runtime_error("Error: Wrong number of arguments.\nUsage: ./PmergeMe 'positive integer sequence'");
    	
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

/**
 * Template function: printElements()
 * - Print all elements of the given container
 */
template <typename C>
void	PmergeMe::printElements(C& container) {
	for (typename C::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
	
/**
 * Ford-Johnson algorithm:
 * 1 - Pair elements into (max, min)
 * 2 - Store elements into group A (bigger values) and B (smaller values)
 * 3 - Recursively sort the group of maximums (group A)
 * 4 - Insert minimums back optimally into sorted list by:
 * 	 - Defining the order elements of B should be insert into A
 *   - Inserting group B elements into the sorted group A
 */

// Merge Insertion sorting implementation for vector
void PmergeMe::mergeInsertionSortVector(std::vector<int>& container) {
	
	int size = container.size();
	if (size < 2)
		return ;
	
	std::vector<std::pair<int, int>> pairs;
	for (int i = 0; i < size - 1; i += 2) {
		int first = container[i];
		int second = container[i + 1];
		if (first < second)
			pairs.emplace_back(second, first);
		else
			pairs.emplace_back(first, second);
	}
	
	std::vector<int> A, B;
	for (const auto& p : pairs) {
		A.push_back(p.first);
		B.push_back(p.second);
	}
	if (size % 2 == 1)
		A.push_back(container.back());

	mergeInsertionSortVector(A);

	std::vector<size_t> insertOrder = generateOptimalInsertOrder(B.size());
	for (size_t index : insertOrder) { // For each index in the insertOrder ...
		if (index < B.size())
			binaryInsertion(A, B[index]);
	}
	container = A;
}

// Merge Insertion sorting implementation for deque
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& container) {
	
	int size = container.size();
	if (size < 2)
		return ;
	
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
	
	std::deque<int> A, B;
	for (const auto& p : pairs) {
		A.push_back(p.first);
		B.push_back(p.second);
	}
	if (size % 2 == 1)
		A.push_back(container.back());

	mergeInsertionSortDeque(A);

	std::vector<size_t> insertOrder = generateOptimalInsertOrder(B.size());
	for (size_t index : insertOrder) {
		if (index < B.size())
			binaryInsertion(A, B[index]);
	}
	container = A;
}

/**
 * Generate Jacobsthal sequence up to a given limit.
 * 
 * Jacobsthal sequence is defined as: J(n) = J(n-1) + 2 * J(n-2), where: J(0) = 0, J(1) = 1
 * It returns std::vector<size_t> containing the Jacobsthal numbers ({0, 1, 3, 5, ...}).
 */
std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t limit) {
	std::vector<size_t> sequence = {0, 1};
	while (sequence.back() < limit) {
		sequence.push_back(sequence[sequence.size() - 1] + 2 * sequence[sequence.size() - 2]);
	}
	return (sequence);
}

/**
 * Generate optimal insertion order based on Jacobsthal sequence.
 *
 * This function computes the order in which elements from container B
 * should be inserted into container A during Merge-Insertion sort.
 * 
 * It first uses Jacobsthal numbers as priority indices, ensuring a efficient 
 * insertion pattern. Any unused indices are appended at the end in ascending order. 
 * It returns a sequence of indices (full permutation of [0, ..., bSize - 1]).
 */
std::vector<size_t> PmergeMe::generateOptimalInsertOrder(size_t bSize) {

	std::vector<size_t> jcbs = generateJacobsthalNumbers(bSize);

	std::vector<size_t>	insertOrder;
	std::vector<bool> 	used(bSize, false);
	// Insert indices corresponding to Jacobsthal numbers (skipping J(0) to avoid biasing the first insertion)
	for (size_t i = 1; i < jcbs.size(); i++) 
	{
		size_t jcbsN = jcbs[i];
		if (jcbsN < bSize && !used[jcbsN]) {
			insertOrder.push_back(jcbsN);
			used[jcbsN] = true;
		}
	}
	for (size_t i = 0; i < bSize; i++) {
		if (!used[i]) 
			insertOrder.push_back(i);
	}
	return (insertOrder);
}

/**
 * Template function: binaryInsertion()
 * Insert an element into a sorted container using binary search
 * - Find the correct position for 'n' by binary search 
 * - Insert 'n' at the position found (at index `left`) while keeping the container sorted.
 */
template <typename T>
void PmergeMe::binaryInsertion(T& container, int n) {
    int left = 0;                	// Start of the container
    int right = container.size(); 	// End of the container (exclusive)

    while (left < right) {
        int middle = left + (right - left) / 2;
        if (n < container[middle])
            right = middle;  		// Narrow the search to the left half
        else
            left = middle + 1; 		// Narrow the search to the right half
    }
    container.insert(container.begin() + left, n);
}