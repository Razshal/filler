# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/02/21 15:42:30 by mfonteni         ###   ########.fr        #
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
	  heatmap_copy_grid.c \
	  heatmap_fill.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "compiling project"
	@gcc $(FLAGS) -o $(NAME) $(LIBFT) $(OBJ)
	@echo "project compiled"

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
