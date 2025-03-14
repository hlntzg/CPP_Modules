# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 09:34:50 by hutzig            #+#    #+#              #
#    Updated: 2025/03/14 16:32:06 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	dreamjob

SRC_PATH	=	./sources
HEADER_PATH	=	./includes

SRC 		=	Account.cpp \
				tests.cpp \

SRC_FILES	=	$(addprefix $(SRC_PATH)/,$(SRC))

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -I$(HEADER_PATH)
RM			=	rm -rf

OBJ_PATH	=	./objects/
OBJ 		=	$(addprefix $(OBJ_PATH), $(notdir $(SRC_FILES:.cpp=.o)))

all:			$(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.cpp
			@echo "$(GR)[Compiling] Converting $< >> $@$(RESET)"
			@mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(CY)[✔] Compilation successful: Object files created.$(RESET)"

$(NAME): 	$(OBJ)
			@echo "$(GR)[Linking] Creating executable '$(NAME)'$(RESET)"
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "$(NEW)$(SWAP)[✔] Build complete! Run './$(NAME)'.$(RESET)"

clean:
			@$(RM) $(OBJ) $(OBJ_PATH)
			@echo "$(RE)[✔] Objects files removed.$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RE)[✔] Executable '$(NAME)' removed.$(RESET)"

re:			fclean all

# Colors
CY			= \033[1;36m
YE			= \033[1;33m
GR			= \033[1;32m
RE			= \033[1;31m
RESET		= \033[0m
NEW			= \033[1;1H\033[2J
SWAP		= \033[7m

.PHONY: all clean fclean re
