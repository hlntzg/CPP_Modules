# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 09:23:43 by hutzig            #+#    #+#              #
#    Updated: 2025/03/18 11:18:10 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

SRC_PATH	= ./sources
HEADER_PATH = ./includes

SRC 		= main.cpp \
				PhoneBook.cpp \
				Contact.cpp \

SRC_FILES	= $(addprefix $(SRC_PATH)/,$(SRC))

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++11 -I$(HEADER_PATH)
RM			= rm -rf

OBJ_PATH	=./objects/
OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC_FILES:.cpp=.o)))

all:		$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.cpp
			@echo "$(YELLOW)[Compiling] Converting $< >> $@$(RESET)"
			@mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)[✔] Compilation successful: Object files created.$(RESET)"

$(NAME): 	$(OBJ)
			@echo "$(YELLOW)[Linking] Creating executable '$(NAME)'$(RESET)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "$(NEW)$(SWAP)[✔] Build complete! Run './$(NAME)'.$(RESET)"

clean:
			@$(RM) $(OBJ) $(OBJ_PATH)
			@echo "$(GREEN)[✔] Objects files removed.$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(GREEN)[✔] Executable '$(NAME)' removed.$(RESET)"

re:			fclean all

# Colors
NEW		=\033[1;1H\033[2J
SWAP	=\033[7m
RESET	=\e[0m
BLACK	=\e[0;30m
RED		=\e[0;31m
GREEN	=\e[0;32m
YELLOW	=\e[0;33m
BLUE	=\e[0;34m
PURPLE	=\e[0;35m
CYAN	=\e[0;36m
WHITE	=\e[0;37m
GREY	=\e[0;39m

.PHONY: all clean fclean re
