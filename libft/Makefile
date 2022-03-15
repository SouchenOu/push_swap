# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 16:59:15 by souchen           #+#    #+#              #
#    Updated: 2022/03/11 21:25:59 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

FILE = 	ft_atoi.c  ft_calloc.c ft_isalnum.c \
	 ft_isdigit.c  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_strncmp.c ft_putuns_fd.c ft_putnbrX.c  ft_put0x.c ft_putnstr.c \
	 ft_printf_chr.c ft_printf_nbr.c ft_printf_utils.c ft_printf.c ft_nbrlen.c ft_bzero.c \
	 ft_atoi.c get_next_line.c get_next_line_utils.c

OBJ = $(FILE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc ${CFLAGS} -c ${FILE}
	ar rc $(NAME) ${OBJ}

fclean:	clean
	rm -f libft.a

clean:
	rm -f ${OBJ}

re:	fclean all
