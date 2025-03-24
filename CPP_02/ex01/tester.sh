#! /bin/bash

# Colors
RESET='\e[0m'
BLACK='\e[0;30m'
RED='\e[0;31m'
GREEN='\e[0;32m'
YELLOW='\e[0;33m'
BLUE='\e[0;34m'
MAGENTA='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'
GREY='\e[0;39m'

echo -e "\n${MAGENTA}Testing CPP02 'Exercise 01: Fixed'\n${RESET}"

make 

if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

echo -e "\nCompilation successful. Running tests..."

# Expected output
echo -e "Default constructor called" > expected_output
echo -e "Int constructor called" >> expected_output
echo -e "Float constructor called" >> expected_output
echo -e "Copy constructor called" >> expected_output
echo -e "Copy assignment operator called" >> expected_output
echo -e "Float constructor called" >> expected_output
echo -e "Copy assignment operator called" >> expected_output
echo -e "Destructor called" >> expected_output
echo -e "a is 1234.43" >> expected_output
echo -e "b is 10" >> expected_output
echo -e "c is 42.4219" >> expected_output
echo -e "d is 10" >> expected_output
echo -e "a is 1234 as integer" >> expected_output
echo -e "b is 10 as integer" >> expected_output
echo -e "c is 42 as integer" >> expected_output
echo -e "d is 10 as integer" >> expected_output
echo -e "Destructor called" >> expected_output
echo -e "Destructor called" >> expected_output
echo -e "Destructor called" >> expected_output
echo -e "Destructor called" >> expected_output

# Run the program
echo -e "${CYAN}\nTest${RESET}"
./Fixed > test_output

# Compare output with expected result
if diff -q test_output expected_output > /dev/null; then
    echo -e "${GREEN}OK${RESET}"
else
    echo -e "${RED}KO${RESET}"
fi

# Cleanup
echo -e "\nCleaning up..."
make fclean

echo -e "${GREEN}[✔] All tests completed.${RESET}"

