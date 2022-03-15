# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 15:24:58 by souchen           #+#    #+#              #
#    Updated: 2022/03/11 21:24:53 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME_M = push_swap
NAME_B = checker
RM = rm -rf
FILES_M = push_swap.c push_swap_utils.c parse.c operations.c sort_6_to_ends.c big_sort_utils.c \
       	Dealing_with_actions.c sort_2_to_5.c
OBJ_FILES_M = $(FILES_M:.c=.o)
FILES_B = checker-file/checker.c checker-file/checker_operations.c checker-file/checker_utils.c \
	  checker-file/checker_actions.c
OBJ_FILES_B= $(FILES_B:.c=.o)
HEADER = header/push_swap.h

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME_M) $(NAME_B)

$(NAME_M): $(OBJ_FILES_M) $(LIBFT)
	gcc $(OBJ_FILES_M) $(LIBFT) -o $(NAME_M)
$(NAME_B): $(OBJ_FILES_B) $(LIBFT)
	gcc $(OBJ_FILES_B) $(LIBFT) -o $(NAME_B)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
$(LIBFT):
	make -C libft
	make clean -C libft

clean:
	$(RM) $(OBJ_FILES_M)
	$(RM) $(OBJ_FILES_B)

fclean: clean
	$(RM) $(NAME_M)
	$(RM) $(NAME_B)
	$(RM) libft/libft.a

re: fclean all
