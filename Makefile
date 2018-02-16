# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/02/16 17:40:20 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mfonteni.filler
PRINTFUNC = printf_functions/
LIBDIR = libft/
LIBFT = ./libft/libftprintf.a
SRC = filler.c \
	  parsers.c \
	  placer.c \
	  structs.c \
	  heatmap.c \
	  fallback_player.c \
	  grid_functions.c \
	  debug.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) libft/ft_print_split.c -fsanitize=address -g3

$(LIBFT):
	make -C $(LIBDIR)

%.o:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
