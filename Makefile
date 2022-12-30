# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 14:46:31 by iouardi           #+#    #+#              #
#    Updated: 2022/12/30 17:31:17 by iouardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 			parsin

FLAGS=			-Wall -Werror -Wextra

CC=				gcc

SRC_FILES=		parsing.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				ft_split.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_substr.c

HEADER_FILES=	get_next_line/get_next_line.h

OBJ_FILES=			$(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HEADER_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete
	find . -name "*.a" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
