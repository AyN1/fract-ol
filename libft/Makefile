# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atbicer <atbicer@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 04:40:04 by atbicer           #+#    #+#              #
#    Updated: 2023/12/26 22:13:50 by atbicer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#PATHS
#VPATH	=	src:src/conversion:src/list:src/memory:src/output:src/string
SRCS	=	ft_isdigit.c ft_strlen.c ft_bzero.c ft_isascii.c ft_memcpy.c \
			ft_isprint.c ft_isalpha.c ft_memset.c ft_isalnum.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJECTS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


BONUS_OBJ = $(SRCS:.c=.o) $(BONUS:.c=.o)

#Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $(BONUS_OBJ)

test: $(NAME)
	@gcc $(NAME) main.c && clear && ./a.out

btest:
	@clear && gcc bmain.c -o bmain libft.a && ./bmain

clean:
	@echo "running clean"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "running fclean"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
