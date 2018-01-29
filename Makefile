# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/01/29 18:19:02 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mfonteni.filler
PRINTFUNC = printf_functions/
LIBDIR = libft/
SRC = filler.c \
	  parsers.c \
	  placer.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

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
