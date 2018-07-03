# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adobrito <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 18:56:39 by adobrito          #+#    #+#              #
#    Updated: 2018/01/14 23:16:52 by adobrito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./fillit_srcs
INC = ./fillit_srcs
LIB = ./libft

FUNCTIONS = assemble_tetrimino assembly_tools main read_tetrimino \
			validate_tetrimino validation_tools create_grid \
			solve_tetris solve_tools
OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRCS = $(patsubst %,$(SRC)/%.c,$(FUNCTIONS))

CC = gcc
COMPILATION_FLAGS = -Wall -Werror -Wextra
LIB_PATH = -L $(LIB) -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB)
	@$(CC) -I $(LIB) -I $(INC) $(COMPILATION_FLAGS) -c $(SRCS)
	@$(CC) $(OBJ) $(LIB_PATH) -o $(NAME)

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
