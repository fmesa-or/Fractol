# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 21:28:15 by fmesa-or          #+#    #+#              #
#    Updated: 2026/04/02 16:20:20 by fmesa-or         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME		:= fractol

#Compile
CC			:= gcc

#Flags
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code

#MLX42
MLX42_DIR	:= ./lib/MLX42
MLX42		:= $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS	:= -ldl -lglfw -pthread -lm

#PRINTF
PRINTF_DIR	:= ./lib/fr_printf
PRINTF		:= $(PRINTF_DIR)/fr_printf.a

#LIBFT
LIBFT_DIR		:= ./lib/libft
LIBFT			:= $(LIBFT_DIR)/libft.a

#Sources
SRCS		:= ./src/hooks/keys.c ./src/hooks/scroll.c \
			   ./src/sets/julia/indexjulia.c ./src/sets/julia/utilsjulia.c ./src/sets/mandelbrot/indexman.c ./src/sets/mandelbrot/utilsman.c \
			   ./src/utils/color.c ./src/utils/error.c ./src/utils/init.c ./src/utils/render.c ./src/utils/zoom.c \
			   ./src/main.c

#Objects
OBJS		:= ${SRCS:.c=.o}

#Headers
HEADERS		:= -I ./include -I $(MLX42_DIR)/include -I $(PRINTF_DIR) -I $(LIBFT_DIR)

#COLORS
COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(MLX42) $(PRINTF) $(LIBFT) $(HEADERS) -lglfw -L /usr/local/opt/glfw/lib/ -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(COLOR_INFO)Compiling: $(notdir $<)$(COLOR_RESET)\t\t"
	@sleep 0.25
	@printf "✅\n"

$(MLX42):
	@printf "$(COLOR_INFO) Building MLX...$(COLOR_RESET)\t\t"
	@make -C $(MLX42_DIR)
	@sleep 0.25
	@printf "✅\n"

$(PRINTF):
	@printf "$(COLOR_INFO) Building fr_printf...$(COLOR_RESET)\t\t"
	@make -C $(PRINTF_DIR)
	@sleep 0.25
	@printf "✅\n"

$(LIBFT):
	@printf "$(COLOR_INFO) Building libft...$(COLOR_RESET)\t\t"
	@make -C $(LIBFT_DIR)
	@sleep 0.25
	@printf "✅\n"

clean:
	@printf "$(COLOR_INFO) Cleaning as fast as I can$(COLOR_RESET)\t"
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@sleep 0.25
	@printf "✅\n"

fclean: clean
	@printf "$(COLOR_INFO) Deleting fractol$(COLOR_RESET)\t\t"
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@sleep 0.25
	@printf "✅\n"

re: fclean clean all

.PHONY: all, clean, fclean, re, libmlx