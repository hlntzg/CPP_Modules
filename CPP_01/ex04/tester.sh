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

echo -e "\n${MAGENTA}Testing CPP01 'Exercise 04: Sed is for losers'\n${RESET}"

#!/bin/bash

# Compile the program
make 

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

echo -e "\nCompilation successful. Running tests..."

# Create a test file
echo -e "Hello World\nThis is a test file.\nHello again!" > test1.txt

# Expected output
echo -e "Hi World\nThis is a test file.\nHi again!" > expected1.txt

# Run the program with a valid replacement
echo -e "${CYAN}\nTest 1: 'Hello', 'Hi'${RESET}"
./Sed_is_for_losers test1.txt "Hello" "Hi"

# Compare output with expected result
if diff -q test1.txt.replace expected1.txt > /dev/null; then
    echo -e "${GREEN}OK${RESET}"
else
    echo -e "${RED}KO${RESET}"
fi

# Create a test file
echo -e "Hello World\nThis is a test file.\nHello again!" > test2.txt

# Expected output
echo -e "Hello World\nThis is a test file.\nHello again!" > expected2.txt

# Run the program with a valid replacement
echo -e "${CYAN}\nTest 2: no match string to be replaced${RESET}"
./Sed_is_for_losers test2.txt "Hi" "Goodbye"

# Compare output with expected result
if diff -q test2.txt.replace expected2.txt > /dev/null; then
    echo -e "${GREEN}OK${RESET}"
else
    echo -e "${RED}KO${RESET}"
fi

# Create a test file
echo -e "Hello World\nTh1s 1s a test f1le.\nHello aga1n!" > test3.txt

# Expected output
echo -e "Hell0 W0rld\nTh1s 1s a test f1le.\nHell0 aga1n!" > expected3.txt

# Run the program with a valid replacement
echo -e "${CYAN}\nTest 3: 'o', '0'${RESET}"
./Sed_is_for_losers test3.txt "o" "0"

# Compare output with expected result
if diff -q test3.txt.replace expected3.txt > /dev/null; then
    echo -e "${GREEN}OK${RESET}"
else
    echo -e "${RED}KO${RESET}"
fi

# Create a test file
echo -e "Hello World\nThis is a test file.\nHello again!" > test4.txt

# Expected output
echo -e "_%$@^-& World\nThis is a test file.\n_%$@^-& again!" > expected4.txt

# Run the program with a valid replacement
echo -e "${CYAN}\nTest 4: 'Hello', '_%$@^-&'${RESET}"
./Sed_is_for_losers test4.txt "Hello" "_%$@^-&"

# Compare output with expected result
if diff -q test4.txt.replace expected4.txt > /dev/null; then
    echo -e "${GREEN}OK${RESET}"
else
    echo -e "${RED}KO${RESET}"
fi

# Run the program with an empty search string (should fail)
echo -e "${CYAN}\nTest 5: Empty search string${RESET}"
./Sed_is_for_losers test.txt "" "Hi"

# Run the program with a non-existent file (should fail)
echo -e "${CYAN}\nTest 6: Non-existent file${RESET}"
./Sed_is_for_losers nonexistent.txt "Hello" "Hi"

# Cleanup
echo -e "\nCleaning up..."
make fclean

echo -e "${GREEN}[✔] All tests completed.${RESET}"
