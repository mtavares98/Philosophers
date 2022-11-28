# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 22:56:59 by mtavares          #+#    #+#              #
#    Updated: 2022/11/22 15:08:02 by mtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(SRCS_DIR)/atoi.c \
				$(SRCS_DIR)/eat.c \
				$(SRCS_DIR)/exit_free.c \
				$(SRCS_DIR)/have_last_arg.c \
				$(SRCS_DIR)/init.c \
				$(SRCS_DIR)/is_death.c \
				$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/print_message.c \
				$(SRCS_DIR)/threads.c \
				$(SRCS_DIR)/time.c \

SRCS_DIR	=	srcs

OBJS	= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

NAME		=	philo

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -pthread -g -fsanitize=address #-fsanitize=thread

RM			=	rm -rf

all:		$(NAME)


$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
