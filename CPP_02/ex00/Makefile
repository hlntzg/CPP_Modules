
NAME		=	Fixed

SRC_PATH	=	./sources
HEADER_PATH	=	./includes

SRC 		=	main.cpp \
				Fixed.cpp \

SRC_FILES	=	$(addprefix $(SRC_PATH)/,$(SRC))

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -I$(HEADER_PATH)
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
			@echo "[✔] Objects files removed."

fclean:		clean
			@$(RM) $(NAME)
			@echo "[✔] Executable '$(NAME)' removed."

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
