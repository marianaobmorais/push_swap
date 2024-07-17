# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 18:44:48 by mariaoli          #+#    #+#              #
#    Updated: 2024/07/04 15:25:02 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CHECKER = checker

P_SLIB = push_swap.a
LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS = check_args.c assign_index.c assign_target.c free_stack.c init.c add_to_back.c rotates.c push.c swap.c move_cheapest.c cheapest_node.c sorts.c big_sort.c node_limits.c

OBJS = $(SRCS:.c=.o)

MAIN = main.c
CHECKER_OBJ = checker.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

all: $(NAME)

$(NAME): $(P_SLIB) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) $(P_SLIB) -o $(NAME)

$(P_SLIB): $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	cp $(LIBFT_DIR)/$(LIBFT) $(P_SLIB)
	ar rcs $(P_SLIB) $(OBJS)

$(LIBFT_DIR)/$(LIBFT):
	make all -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER) $(P_SLIB)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean
	$(MAKE) all

bonus: $(CHECKER)

$(CHECKER): $(P_SLIB) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(P_SLIB) -o $(CHECKER)

.PHONY: all clean fclean re bonus
