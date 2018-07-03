# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adobrito <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 03:45:01 by adobrito          #+#    #+#              #
#    Updated: 2017/12/23 01:32:58 by adobrito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_atoi \
		ft_itoa \
		ft_itoa_base \
		ft_bzero \
		ft_isalpha \
		ft_isalnum \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_lstadd \
		ft_lstappend \
		ft_lstmap \
		ft_lstnew \
		ft_lstiter \
		ft_lstdel \
		ft_lstdelone \
		ft_memalloc \
		ft_memcpy \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memdel \
		ft_memmove \
		ft_memset \
		ft_power \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putchar \
		ft_putchar_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_strcat \
		ft_strlcat \
		ft_strncat \
		ft_strcpy \
		ft_strncpy \
		ft_strlen \
		ft_strchr \
		ft_strrchr \
		ft_strdup \
		ft_strjoin \
		ft_strstr \
		ft_strnstr \
		ft_strcmp \
		ft_strncmp \
		ft_strdel \
		ft_strclr \
		ft_striter \
		ft_striteri \
		ft_strequ \
		ft_strnequ \
		ft_strmap \
		ft_strmapi \
		ft_strnew \
		ft_strtrim \
		ft_strsplit \
		ft_strsub \
		ft_tolower \
		ft_toupper \
		ft_isupper \
		ft_islower \
		ft_abs \
		ft_print_memory \
		ft_word_count \
		ft_word_counts

OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRC = $(patsubst %,%.c,$(FUNCTIONS))
COMPILATION_FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I . $(COMPILATION_FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
