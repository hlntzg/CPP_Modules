# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 09:07:05 by hutzig            #+#    #+#              #
#    Updated: 2025/04/21 09:08:22 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	btc

SRC_PATH	=	./sources
HEADER_PATH	=	./includes

SRC 		=	main.cpp \
				BitcoinExchange.cpp \

SRC_FILES	=	$(addprefix $(SRC_PATH)/,$(SRC))

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++11 -I$(HEADER_PATH)
RM			=	rm -rf

OBJ_PATH	=	./objects/
OBJ 		=	$(addprefix $(OBJ_PATH), $(notdir $(SRC_FILES:.cpp=.o)))

all:			$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.cpp
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

# Colors
RESET		= \033[0m
SWAP		= \033[7m

.PHONY: all clean fclean re
