/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:57:36 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/18 14:25:55 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <cassert> // For assert

#if 0
static void	testSubjectDefault();
static void	testSequenceContainerList();
static void	testSequenceContainerVector();

int main(void)
{	
	testSubjectDefault();
	testSequenceContainerList();
	testSequenceContainerVector();
	
	return (0);
}

static void	testSubjectDefault() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: MutantStack functionality ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}	
	std::stack<int>	s(mstack);
}

static void	testSequenceContainerList() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Sequence Container: std::list ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	testSequenceContainerVector() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Sequence Container: std::vector ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	std::vector<int>	vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	//[...]
	vec.push_back(0);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "-----------------------------------------" << std::endl;
}
#endif

#if 1

#define COLOR "\033[0;32m"
#define RESET "\033[0;0m"

static void	testCopyAndAssignment();
static void	testDefaultStack();
static void	testForwardIteration();
static void	testReverseIteration();

int	main(void) {

	testCopyAndAssignment();
	testDefaultStack();
	testForwardIteration();
	testReverseIteration();

	return (0);
}

static void	testCopyAndAssignment() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy and Assignment Operator ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	MutantStack<int> m1;
    m1.push(1);
	m1.push(2);
	m1.push(3);

    MutantStack<int> m2 = m1;
    assert(m2.top() == 3);
    m2.pop();
    assert(m2.top() == 2);
    assert(m1.top() == 3);  // m1 is unaffected

    MutantStack<int> m3;
    m3 = m1;  // Assignment
    assert(m3.size() == 3);
    assert(m3.top() == 3);
	std::cout << COLOR << "[✔] Copy constructor and Copy Assignment Operator." << RESET << std::endl;
}

static void	testDefaultStack() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default Stack behaviour ]" << std::endl
				<< "-----------------------------------------" << std::endl;
    
	MutantStack<int> m2;
    m2.push(10);
    m2.push(20);
    m2.push(30);
	
	std::cout << "MutantStack elements: ";
	MutantStack<int>::iterator it_m = m2.begin();
	MutantStack<int>::iterator ite_m = m2.end();
	while (it_m != ite_m)
	{
		std::cout << *it_m;
		it_m++;
		if (it_m != ite_m)
			std::cout << " ";
	}
	std::cout << std::endl;
	
	std::cout << "MutantStack size: " << m2.size() << std::endl;
	std::cout << "MutantStack top element: " << m2.top() << std::endl;
    
	assert(m2.size() == 3);
    assert(m2.top() == 30);
	
	std::cout << "Removing top element from MutantStack ..." << std::endl;
    m2.pop();
	std::cout << "MutantStack size: " << m2.size() << std::endl;
	std::cout << "MutantStack top element: " << m2.top() << std::endl;
    assert(m2.top() == 20);
    assert(m2.size() == 2);
	std::cout << COLOR << "[✔] Default stack behaviour for MutantStack." << RESET << std::endl;
}

static void	testForwardIteration() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Forward Iteration ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	MutantStack<int> m3;
    for (int i = 1; i <= 5; ++i)
		m3.push(i);
	
	std::cout << "MutantStack forward iterator output: ";
	MutantStack<int>::iterator it_m = m3.begin();
	MutantStack<int>::iterator ite_m = m3.end();
	while (it_m != ite_m)
	{
		std::cout << *it_m;
		it_m++;
		if (it_m != ite_m)
			std::cout << " ";
	}
	std::cout << std::endl;

    std::vector<int> values;
    for (auto it = m3.begin(); it != m3.end(); it++)
		values.push_back(*it);

	std::cout << "MutantStack forward iterator output -> std::vector: ";
	std::vector<int>::iterator it_v = values.begin();
	std::vector<int>::iterator ite_v = values.end();
	while (it_v != ite_v)
	{
		std::cout << *it_v;
		it_v++;
		if (it_v != ite_v)
			std::cout << " ";
	}
	std::cout << std::endl;

    assert(values == std::vector<int>({1, 2, 3, 4, 5}));
	std::cout << COLOR << "[✔] Forward iteration for MutantStack." << RESET << std::endl;
}

static void	testReverseIteration() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Reverse Iteration ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	MutantStack<int> m4;
    for (int i = 1; i <= 5; ++i)
		m4.push(i);

	std::cout << "MutantStack forward iterator output: ";
	MutantStack<int>::iterator it_m = m4.begin();
	MutantStack<int>::iterator ite_m = m4.end();
	while (it_m != ite_m)
	{
		std::cout << *it_m;
		it_m++;
		if (it_m != ite_m)
			std::cout << " ";
	}
	std::cout << std::endl;
	
    std::vector<int> values;
    for (auto it = m4.rbegin(); it != m4.rend(); it++)
		values.push_back(*it);
	
	std::cout << "MutantStack reverse iterator output -> std::vector: ";
	std::vector<int>::iterator it_v = values.begin();
	std::vector<int>::iterator ite_v = values.end();
	while (it_v != ite_v)
	{
		std::cout << *it_v;
		it_v++;
		if (it_v != ite_v)
			std::cout << " ";
	}
	std::cout << std::endl;

    assert(values == std::vector<int>({5, 4, 3, 2, 1}));
	std::cout << COLOR << "[✔] Reverse iteration for MutantStack." << RESET << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
}

#endif 
