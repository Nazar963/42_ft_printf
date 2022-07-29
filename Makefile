# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:54:00 by naal-jen          #+#    #+#              #
#    Updated: 2022/07/29 10:42:56 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I.
AR = ar
ARF = -rcs
NAME = libftprintf.a

MAN = src/ft_printf \
		 src/handle_address \
		 src/handle_d_i
MANFC = $(addsuffix .c, $(MAN))
MANO = $(MANFC:.c=.o)


all: $(NAME)

$(NAME): $(MANO)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	$(MAKE) clean -C ./libft
	@rm -f $(MANO)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re