# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 08:54:31 by hutzig            #+#    #+#              #
#    Updated: 2025/03/17 12:43:01 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SRC 		= megaphone.cpp

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJ_PATH	=./obj/
OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

all:		$(NAME)

$(OBJ_PATH)%.o: %.cpp
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

test:		all
			@./megaphone_tester.sh

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
