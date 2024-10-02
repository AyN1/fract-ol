# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 14:19:20 by atbicer           #+#    #+#              #
#    Updated: 2024/09/22 14:19:37 by atbicer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = events.c init.c main.c math_utils.c render.c string_utils.c
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
HEADER = -I .
all: $(NAME)

$(NAME): libft.a $(OBJ)
	@gcc $(CFLAG) $(SRC) libft/libft.a /usr/local/lib/libmlx.a -framework OpenGL -framework Appkit -o $(NAME)
	@echo $(NAME) compiled
# $@ is for %.o, i.e the name of the rule, and %< is for %^.c , i.e the dependecies of the rule
%.o : %.c
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<
	@echo fractol dependecies compiled with $(CFLAGS)
libft.a:
	@make -C ./libft

clean:
	@rm -rf $(OBJ)
	@make -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re : fclean all

.PHONY: all, clean, fclean, re
