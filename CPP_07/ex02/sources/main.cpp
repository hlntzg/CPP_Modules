/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:04:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/15 15:41:24 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1
#include "Array.hpp"
#include <iostream>
#include <string>
#include <cassert>	// For assert

#define COLOR "\033[0;35m"
#define RED "\033[0;31m"
#define RESET "\033[0;0m"

static void	testDefaultConstructor();
static void	testParameterizedConstructor();
static void	testCopyConstructor();
static void	testCopyAssignmentOperator();
static void	testOutOfBounds();

int	main(void) {

	testDefaultConstructor();
	testParameterizedConstructor();
	testCopyConstructor();
	testCopyAssignmentOperator();
	testOutOfBounds();

	return (0);
}

static void	testDefaultConstructor() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Default Constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		
		Array<char>	c;
		std::cout << COLOR << "[ Char array ]" << RESET << std::endl;
		std::cout << "Size: " << c.size() << std::endl;
		assert(c.size() == 0);
		std::cout << "[✔] Default constructor for character array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<int>	i;
		std::cout << COLOR << "[ Int array ]" << RESET << std::endl;
		std::cout << "Size: " << i.size() << std::endl;
		assert(i.size() == 0);
		std::cout << "[✔] Default constructor for integer array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<float>	f;
		std::cout << COLOR << "[ Float array ]" << RESET << std::endl;
		std::cout << "Size: " << f.size() << std::endl;
		assert(f.size() == 0);
		std::cout << "[✔] Default constructor for float array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<double>	d;
		std::cout << COLOR << "[ double array ]" << RESET << std::endl;
		std::cout << "Size: " << d.size() << std::endl;
		assert(d.size() == 0);
		std::cout << "[✔] Default constructor for double array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<std::string>	s;
		std::cout << COLOR << "[ String array ]" << RESET << std::endl;
		std::cout << "Size: " << s.size() << std::endl;
		assert(s.size() == 0);
		std::cout << "[✔] Default constructor for string array." << std::endl;
	
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	testParameterizedConstructor() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Parameterized Constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {

		Array<char>	c(1);
		std::cout << COLOR << "[ Char array ]" << RESET << std::endl;
		std::cout << "Size: " << c.size() << std::endl;
		assert(c.size() == 1);
		for (unsigned int j = 0; j < c.size(); j++) {
			c[j] = 'a' + j;
			std::cout << "c[" << j << "] = " << c[j] << std::endl;
		}
		std::cout << "[✔] Parameterized constructor for character array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<int>	i(3);
		std::cout << COLOR << "[ Int array ]" << RESET << std::endl;
		std::cout << "Size: " << i.size() << std::endl;
		assert(i.size() == 3);
		for (unsigned int j = 0; j < i.size(); j++) {
			i[j] = j * 10;
			std::cout << "i[" << j << "] = " << i[j] << std::endl;
		}
		std::cout << "[✔] Parameterized constructor for integer array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<float>	f(3);
		std::cout << COLOR << "[ Float array ]" << RESET << std::endl;
		std::cout << "Size: " << f.size() << std::endl;
		assert(f.size() == 3);
		for (unsigned int j = 0; j < f.size(); j++) {
			f[j] = j * 1.1f;
			std::cout << "i[" << j << "] = " << f[j] << std::endl;
		}
		std::cout << "[✔] Parameterized constructor for float array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<double>	d(3);
		std::cout << COLOR << "[ double array ]" << RESET << std::endl;
		std::cout << "Size: " << d.size() << std::endl;
		assert(d.size() == 3);
		for (unsigned int j = 0; j < d.size(); j++) {
			d[j] = j * 1.123456789;
			std::cout << "i[" << j << "] = " << d[j] << std::endl;
		}
		std::cout << "[✔] Parameterized constructor for double array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<std::string>	s(10);
		std::cout << COLOR << "[ String array ]" << RESET << std::endl;
		std::cout << "Size: " << s.size() << std::endl;
		assert(s.size() == 10);
		for (unsigned int j = 0; j < s.size(); j++) {
			std::string str = "string_" + std::to_string(j + 1);
			s[j] = str;
			std::cout << "i[" << j << "] = " << s[j] << std::endl;
		}
		std::cout << "[✔] Parameterized constructor for string array." << std::endl;
	
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	testCopyConstructor() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy Constructor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {

		Array<char>	c(10);
		std::cout << COLOR << "[ Char array ]" << RESET << std::endl;
		std::cout << "Size of c (original): " << c.size() << std::endl;
		assert(c.size() == 10);
		for (unsigned int j = 0; j < c.size(); j++) {
			c[j] = 'A' + j;
			std::cout << "c[" << j << "] = " << c[j] << std::endl;
		}
		Array<char>	cCopy(c);
		std::cout << "Size of cCopy (copy): " << cCopy.size() << std::endl;
		assert(cCopy.size() == 10);
		for (unsigned int j = 0; j < cCopy.size(); j++) {
			std::cout << "cCopy[" << j << "] = " << cCopy[j] << std::endl;
		}
		std::cout << "[✔] Copy constructor for character array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		Array<int>	i(5);
		std::cout << COLOR << "[ Int array ]" << RESET << std::endl;
		std::cout << "Size of i (original): " << i.size() << std::endl;
		assert(i.size() == 5);
		for (unsigned int j = 0; j < i.size(); j++) {
			i[j] = j + 100;
			std::cout << "i[" << j << "] = " << i[j] << std::endl;
		}
		Array<int>	iCopy(i);
		std::cout << "Size of iCopy (copy): " << i.size() << std::endl;
		assert(i.size() == 5);
		for (unsigned int j = 0; j < iCopy.size(); j++) {
			std::cout << "i[" << j << "] = " << iCopy[j] << std::endl;
		}
		std::cout << "[✔] Copy constructor for integer array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<std::string>	s(3);
		std::cout << COLOR << "[ String array ]" << RESET << std::endl;
		std::cout << "Size of s (original): " << s.size() << std::endl;
		assert(s.size() == 3);
		for (unsigned int j = 0; j < s.size(); j++) {
			std::string str = "another_string_" + std::to_string(j + 1);
			s[j] = str;
			std::cout << "i[" << j << "] = " << s[j] << std::endl;
		}
		Array<std::string>	sCopy(s);
		std::cout << "Size of sCopy (copy): " << sCopy.size() << std::endl;
		assert(s.size() == 3);
		for (unsigned int j = 0; j < s.size(); j++) {
			std::cout << "i[" << j << "] = " << s[j] << std::endl;
		}
		std::cout << "[✔] Copy constructor for string array." << std::endl;

	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	testCopyAssignmentOperator() {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Copy Assignment Operator ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	try {

		Array<char>	c(3);
		std::cout << COLOR << "[ Char array ]" << RESET << std::endl;
		std::cout << "Size of c (original): " << c.size() << std::endl;
		assert(c.size() == 3);
		for (unsigned int j = 0; j < c.size(); j++) {
			c[j] = '*';
			std::cout << "c[" << j << "] = " << c[j] << std::endl;
		}
		Array<char>	C;
		std::cout << "Size of C (default): " << C.size() << std::endl;
		C = c;
		std::cout << "Size of C (after copy assingment): " << C.size() << std::endl;
		for (unsigned int j = 0; j < c.size(); j++)
			assert(c[j] == C[j]);
		for (unsigned int j = 0; j < C.size(); j++) {
			std::cout << "C[" << j << "] = " << C[j] << std::endl;
		}

		std::cout << "Testing for 'deep copy': change 'c' array content" << std::endl;
		std::cout << "Size of c: " << c.size() << std::endl;
		for (unsigned int j = 0; j < c.size(); j++) {
			c[j] = '&';
			std::cout << "c[" << j << "] = " << c[j] << std::endl;
		}
		std::cout << "Size of C: " << C.size() << std::endl;
		for (unsigned int j = 0; j < C.size(); j++) 
			std::cout << "C[" << j << "] = " << C[j] << std::endl;
		std::cout << "[✔] Copy Assignment operator for char array." << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

static void	testOutOfBounds() {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Out of Bounds ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	try {
		Array<int> out(5);
		std::cout << COLOR << "[ Int array ]" << RESET << std::endl;
		std::cout << "Size of out: " << out.size() << std::endl;
		for (unsigned int j = 0; j < out.size(); j++) {
			out[j] = j;
			std::cout << "out[" << j << "] = " << out[j] << std::endl;
		}

		bool caught = false;

		std::cout << "Trying to access index 5 (out of bounds): " << std::endl;
		try {
			out[5] = 100;
		}
		catch (const std::exception &e) {
			caught = true;
			std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
		}
		assert(caught);

		caught = false;
		std::cout << "Trying to access index -1 (out of bounds): " << std::endl;
		try {
			out[-1] = 100;
		}
		catch (const std::exception &e) {
			caught = true;
			std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
		}
		assert(caught);

		std::cout << "[✔] Out-of-bounds access properly handled." << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
}

#endif

#if 0
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
		// Should leak if destructor does not delete the array (free the array)
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		// test index out of range
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
		// test index out of range
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
#endif
