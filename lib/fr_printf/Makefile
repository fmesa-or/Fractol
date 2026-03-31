# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 14:42:25 by fmesa-or          #+#    #+#              #
#    Updated: 2024/05/03 23:46:26 by fmesa-or         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fr_printf.a
CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
CLEAN	= rm -Rf
SRC		= fr_printf.c fr_printf_utils.c fr_printf_utils2.c

OBJS	= $(SRC:.c=.o)
all: $(NAME)
$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)
%.o	: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(CLEAN) $(OBJS)
fclean:
	@$(CLEAN) $(OBJS)
	@$(CLEAN) $(NAME)
re: fclean all
.PHONY	:	all bonus clean fclean re
