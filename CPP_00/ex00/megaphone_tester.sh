#!/bin/bash

RESET='\e[0m'
BLACK='\e[0;30m'
RED='\e[0;31m'
GREEN='\e[0;32m'
YELLOW='\e[0;33m'
BLUE='\e[0;34m'
PURPLE='\e[0;35m'
CYAN='\e[0;36m'
WHITE='\e[0;37m'
GREY='\e[0;39m'

# Tests ex00

echo ./megaphone \"shhhhh... I think the students are asleep...\"
user_output=$(./megaphone "shhhhh... I think the students are asleep...")
if [ "$user_output" = "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." ]
then
	echo -e "${GREEN}OK${RESET}"
else
	echo -e "${RED}KO${RESET}"
fi

echo ./megaphone Damnit \" ! \" \"Sorry students, I thought this thing was off.\"
user_output=$(./megaphone Damnit " ! " "Sorry students, I thought this thing was off.")
if [ "$user_output" = "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." ]
then
	echo -e "${GREEN}OK${RESET}"
else
	echo -e "${RED}KO${RESET}"
fi

echo ./megaphone
user_output=$(./megaphone)
if [ "$user_output" = "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ]
then
	echo -e "${GREEN}OK${RESET}"
else
	echo -e "${RED}KO${RESET}"
fi
