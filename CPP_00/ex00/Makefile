# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 08:54:31 by hutzig            #+#    #+#              #
#    Updated: 2025/03/19 17:16:03 by hutzig           ###   ########.fr        #
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
			@mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "$(SWAP)[✔] Build complete! Run './$(NAME)'.$(RESET)"

clean:
			@$(RM) $(OBJ) $(OBJ_PATH)
			@echo "$(SWAP)[✔] Objects files removed.$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(SWAP)[✔] Executable '$(NAME)' removed.$(RESET)"

re:			fclean all

test:		all
			@./megaphone_tester.sh

# Colors
SWAP	=\033[7m
RESET	=\e[0m

.PHONY: all clean fclean re
