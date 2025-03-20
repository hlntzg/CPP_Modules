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

echo -e "\n${MAGENTA}Testing CPP01 'Exercise 06: Harl filter'\n${RESET}"

#!/bin/bash

# Compile the program
make 

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

echo -e "\nCompilation successful. Running tests..."

echo -e "${CYAN}\nTest 1: No parameter${RESET}"
./harlFilter

echo -e "${CYAN}\nTest 2: Invalid parameter${RESET}"
./harlFilter "I am not sure how tired I am today..."

echo -e "${CYAN}\nTest 3: 'DEBUG'${RESET}"
./harlFilter DEBUG

echo -e "${CYAN}\nTest 4: 'INFO'${RESET}"
./harlFilter INFO

echo -e "${CYAN}\nTest 5: 'WARNING'${RESET}"
./harlFilter WARNING

echo -e "${CYAN}\nTest 6: 'ERROR'${RESET}"
./harlFilter ERROR

# Cleanup
echo -e "\nCleaning up..."
make fclean

echo -e "${GREEN}[✔] All tests completed.${RESET}"
