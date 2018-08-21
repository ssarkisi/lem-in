#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 13:47:36 by ssarkisi          #+#    #+#              #
#    Updated: 2017/11/26 13:47:41 by ssarkisi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

OBJSRC = lemin.c\
		check_line.c\
		handler_of_line.c\
		rooms.c\
		algoritm.c\
		move_ants.c\
		print_progress.c\
		t_data.c\
		check_data.c\
		realloc_d_data.c\


OBJC = $(OBJSRC:%.c=srcs/%.c)
OBJO = $(OBJSRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft

%.o: srcs/%.c
	gcc $(CFLAGS) -c $< -I includes

all: $(NAME)

$(NAME): $(OBJO)
	make -C $(LIBDIR)
	gcc $(CFLAGS) -o $(NAME) $(OBJO) -L./$(LIBDIR) -lft -I includes

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJO)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
