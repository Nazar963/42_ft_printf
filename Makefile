# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 19:54:00 by naal-jen          #+#    #+#              #
#    Updated: 2022/12/11 10:59:10 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I.
AR = ar
ARF = -rcs
NAME = libftprintf.a

MAN = src/ft_printf src/process_address_hex src/process_char_string src/process_hash_flag \
	src/process_int_unsigned src/process_octal src/process_width src/struct_initialize \
	src/process_hash src/helper_address_hex src/helper_address src/hash_helper \
	src/helper_char_string src/helper_int src/helper_width src/string_null \
	src/process_int_unsigned_1 src/helper_width_1 src/helper_int_1 src/helper_int_2 \
	src/process_width_1
MANFC = $(addsuffix .c, $(MAN))
MANO = $(MANFC:.c=.o)

all: $(NAME)

$(NAME): $(MANO)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

# compile:
# 	gcc $(MANO) libft/libft.a

clean:
	$(MAKE) clean -C ./libft
	@rm -f $(MANO)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re
