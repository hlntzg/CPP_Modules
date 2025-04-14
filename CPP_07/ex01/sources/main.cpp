/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:00:37 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/14 16:16:07 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <cctype>	// For std::isalpha, std::toupper
#include <cstddef>	// For size_t
#include <string>	// For std::string

#define COLOR "\033[0;35m"
#define RESET "\033[0;0m"

template <typename T>
void print_element(const T& element) {
    std::cout << element << " ";
}

// Functor (function object) to uppercase character
struct CharToUpper {
    void operator()(char& element) {
        if (std::isalpha(element))
            element = std::toupper(element);
    }
};

// Functor to append "!" to each string
struct AppendExclamation {
    void operator()(std::string& element) {
        element += "!";
    }
};

// Functor to multiply int by 2
struct MultiplyByTwo {
    void operator()(int& element) {
        element *= 2;
    }
};

// Functor to square float values
struct SquareFloat {
    void operator()(float& element) {
        element *= element;
    }
};

// Functor to multiply double by 0.5
struct HalfValue {
    void operator()(double& element) {
        element *= 0.5;
    }
};

static void	testRegularFunction();
static void	testFunctor();
static void	testNullArray();

int	main(void) {

	testRegularFunction();
	testFunctor();
	testNullArray();
	return (0);
}

static void	testRegularFunction(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Regular function ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	std::cout	<< COLOR << "[ Array type: Character ]" << RESET << std::endl;
	char	charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t	charArraySize = sizeof(charArray) / sizeof(charArray[0]);
    
	std::cout << "Using regular function: ";
    iter(charArray, charArraySize, print_element<char>);
    std::cout << std::endl;
	std::cout	<< "-----------------------------------------" << std::endl;

	std::cout	<< COLOR << "[ Array type: String ]" << RESET << std::endl;
	std::string	strArray[] = {"hello", "there", "goodbye", "you"};
    size_t	strArraySize = sizeof(strArray) / sizeof(strArray[0]);
    
	std::cout << "Using regular function: ";
    iter(strArray, strArraySize, print_element<std::string>);
    std::cout << std::endl;
	std::cout	<< "-----------------------------------------" << std::endl;

	std::cout	<< COLOR << "[ Array type: Integer ]" << RESET << std::endl;
	int		intArray[] = {1, 2, 3, 4, 5};
    size_t	intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Using regular function: ";
    iter(intArray, intArraySize, print_element<int>);
    std::cout << std::endl;
	std::cout	<< "-----------------------------------------" << std::endl;

	std::cout	<< COLOR << "[ Array type: Float ]" << RESET << std::endl;
	float	floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t	floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "Using regular function: ";
    iter(floatArray, floatArraySize, print_element<float>);
    std::cout << std::endl;
	std::cout	<< "-----------------------------------------" << std::endl;

	std::cout	<< COLOR << "[ Array type: Double ]" << RESET << std::endl;
	double	doubleArray[] = {0.00001, 0.00002, 0.00003, 0.00004, 0.00005};
    size_t	doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Using regular function: ";
    iter(doubleArray, doubleArraySize, print_element<double>);
    std::cout << std::endl;
}

static void	testFunctor(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Functor ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	std::cout	<< COLOR << "[ Array type: Character ]" << RESET << std::endl;
	char	charArray[] = {'a', 'b', 'c', 'd', 'e', '@', '0', '1', '2', '3'};
    size_t	charArraySize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Using functor (uppercase a-z, A-Z): ";
    CharToUpper uppercase;
    iter(charArray, charArraySize, uppercase);
    iter(charArray, charArraySize, print_element<char>);
    std::cout << std::endl;
	std::cout	<< "-----------------------------------------" << std::endl;

    std::cout   << COLOR << "[ Array type: String ]" << RESET << std::endl;
    std::string strArray[] = {"hello", "world", "functor", "test"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Using functor (append '!'): ";
    AppendExclamation addExclamation;
    iter(strArray, strArraySize, addExclamation);
    iter(strArray, strArraySize, print_element<std::string>);
    std::cout << std::endl;
    std::cout   << "-----------------------------------------" << std::endl;
	
	std::cout	<< COLOR << "[ Array type: Integer ]" << RESET << std::endl;
	int		intArray[] = {1, 2, 3, 4, 5};
    size_t	intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Using functor (multiply by two): ";
    MultiplyByTwo multiply;
    iter(intArray, intArraySize, multiply);
    iter(intArray, intArraySize, print_element<int>);
    std::cout << std::endl;
    std::cout   << "-----------------------------------------" << std::endl;

    std::cout   << COLOR << "[ Array type: Float ]" << RESET << std::endl;
    float floatArray[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    size_t floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "Using functor (square): ";
    SquareFloat square;
    iter(floatArray, floatArraySize, square);
    iter(floatArray, floatArraySize, print_element<float>);
    std::cout << std::endl;
    std::cout   << "-----------------------------------------" << std::endl;
    
	std::cout   << COLOR << "[ Array type: Double ]" << RESET << std::endl;
    double doubleArray[] = {10.0, 20.0, 30.0, 40.0, 50.0};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Using functor (divide by 2): ";
    HalfValue half;
    iter(doubleArray, doubleArraySize, half);
    iter(doubleArray, doubleArraySize, print_element<double>);
    std::cout << std::endl;

}

static void	testNullArray(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Null array ]" << std::endl
				<< "-----------------------------------------" << std::endl;

    char	*nullCharArray = nullptr;
	std::cout	<< COLOR << "[ Array type: null array char ] " << RESET;
    iter(nullCharArray, 0, print_element<char>);
	std::cout	<< "-----------------------------------------" << std::endl;
    
	std::string	*nullStrArray = nullptr;
	std::cout	<< COLOR << "[ Array type: null string ] " << RESET;
    iter(nullStrArray, 0, print_element<std::string>);
	std::cout	<< "-----------------------------------------" << std::endl;

	int		*nullIntArray = nullptr;
	std::cout	<< COLOR << "[ Array type: null array integer ] " << RESET;
    iter(nullIntArray, 0, print_element<int>);
	std::cout	<< "-----------------------------------------" << std::endl;

	float	*nullFloatArray = nullptr;
	std::cout	<< COLOR << "[ Array type: null array float ] " << RESET;
    iter(nullFloatArray, 0, print_element<float>);
	std::cout	<< "-----------------------------------------" << std::endl;

	double	*nullDoubleArray = nullptr;
	std::cout	<< COLOR << "[ Array type: null array double ] " << RESET;
    iter(nullDoubleArray, 0, print_element<double>);
	std::cout	<< "-----------------------------------------" << std::endl;
}

