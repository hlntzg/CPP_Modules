/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:04:11 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/15 12:13:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1
#include "Array.hpp"
#include <iostream>
#include <string>
#include <cassert>	// For assert

#define COLOR "\033[0;35m"
#define RESET "\033[0;0m"

static void	testDefaultConstructor();
static void	testParameterizedConstructor();

int	main(void) {

	testDefaultConstructor();
	testParameterizedConstructor();

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

		Array<char>	c(3);
		std::cout << COLOR << "[ Char array ]" << RESET << std::endl;
		std::cout << "Size: " << c.size() << std::endl;
		assert(c.size() == 3);
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
		std::cout << "[✔] Parameterized constructor for float array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<double>	d(3);
		std::cout << COLOR << "[ double array ]" << RESET << std::endl;
		std::cout << "Size: " << d.size() << std::endl;
		assert(d.size() == 3);
		std::cout << "[✔] Parameterized constructor for double array." << std::endl;
		std::cout << "-----------------------------------------" << std::endl;
		
		Array<std::string>	s(3);
		std::cout << COLOR << "[ String array ]" << RESET << std::endl;
		std::cout << "Size: " << s.size() << std::endl;
		assert(s.size() == 3);
		std::cout << "[✔] Parameterized constructor for string array." << std::endl;
	
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout	<< "-----------------------------------------" << std::endl;
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
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
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
