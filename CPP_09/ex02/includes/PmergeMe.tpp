#include "PmergeMe.hpp"

template <typename C>
void PmergeMe::run(C& container, ContainerType type) {
        
		auto start = std::chrono::high_resolution_clock::now();
		container.clear();
		container.insert(container.end(), getInput().begin(), getInput().end());
        
		mergeInsertSort(container);  // Ford-Johnson sort implementation

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> duration = end - start;
        
		if (type == VECTOR)
			_elapsedTimeVector = duration.count();
		if (type == DEQUE)
			_elapsedTimeDeque = duration.count();
}

template <typename C>
void	PmergeMe::importData(C& container, char **argv) {
        
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
    
template <typename C>
void	PmergeMe::printElements(C& container) {

		for (typename C::const_iterator it = container.begin(); it != container.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
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

	// std::cout << "Before:\n";
	// //printElements(a);
	// printElements(b);

	// 2#	Recursively sort the group A
	mergeInsertSort(A);

	// 3#	Define the order elements of B should be insert into A
	std::vector<size_t> insertOrder = generateOptimalInsertOrder(B.size());

	// std::cout << "Insertion order: ";
	// for (size_t i : insertOrder) std::cout << i << " ";
	// std::cout << std::endl;
	
	// 4#	Insert elements of group B into the sorted group A
	for (size_t index : insertOrder)  { //For each index in the insertOrder…
		if (index < B.size()) {
			binaryInsertion(A, B[index]);
		}
	}

	container = A;
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
