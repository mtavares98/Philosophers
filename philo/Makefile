# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 22:56:59 by mtavares          #+#    #+#              #
#    Updated: 2022/09/09 22:20:00 by mtavares         ###   ########.fr        #
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

NAME		=	philo

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -pthread -g -fsanitize=thread #-fsanitize=thread

RM			=	rm -rf

all:		$(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		$(RM) $(OBJS_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re
