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

echo -e "\n${MAGENTA}Testing CPP02 'Exercise 03: BSP (Binary space partitioning)'\n${RESET}"

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
./BSP

echo -e "${CYAN}\nTest 2: Invalid parameter${RESET}"
./BSP 5 5 0 0 0 0 0 0 

echo -e "${CYAN}\nTest 3: '2.0f 1.0f 0.0f 0.0f 4.0f 0.0f 2.0f 3.0f'${RESET}"
./BSP 2.0 1.0 0.0 0.0 4.0 0.0 2.0 3.0

echo -e "${CYAN}\nTest 4: '-2.0f -1.0f 0.0f 0.0f 4.0f 0.0f 2.0f 3.0f'${RESET}"
./BSP -2.0 -1.0 0.0 0.0 4.0 0.0 2.0 3.0

echo -e "${CYAN}\nTest 5: '2 1 0 0 4 0 0 4'${RESET}"
./BSP 0 0 0 0 4 0 0 4 

echo -e "${CYAN}\nTest 6: '1.1 2.3 0 0 4 0 0 4'${RESET}"
./BSP 1.1 2.3 0 0 4 0 0 4 

# Cleanup
echo -e "\nCleaning up..."
make fclean

echo -e "${GREEN}[✔] All tests completed.${RESET}"

