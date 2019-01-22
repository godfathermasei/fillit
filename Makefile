#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apavlov <apavlov@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 18:14:48 by apavlov           #+#    #+#              #
#    Updated: 2018/11/23 18:14:52 by apavlov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = cc

NAME = fillit

SRC_DIR = srcs/

SRC = main.c read_input.c solve.c output.c teterino.c algorithm.c

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

LIB = libft/

INCLUDES = srcs/

FLAGS = -Wall -Wextra -Werror

$(NAME): lib $(OBJ)
	@$(CC) $(FLAGS) -I $(INCLUDES) -L$(LIB) -lft $(OBJ) -o $(NAME)

all: $(NAME)

lib:
	@make -C $(LIB)

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ) 

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
