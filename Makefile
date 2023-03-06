# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douglas <douglas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 14:52:37 by douglas           #+#    #+#              #
#    Updated: 2023/03/02 14:54:21 by douglas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc -pthread
FLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -rf

FILES	=	main \
			checker \
			initialize \
			routine	\
			time 	\
			utils	\
			create \
			kill_philos \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.c.o: $(SRCS)
		@$(CC) $(FLAGS) -c $< -o  $@

$(NAME): $(OBJS)
		@$(CC) -o $@  $^
		@printf "Compiled\n"

all: $(NAME)

clean:
		@printf "Deleting ...\n"
		@$(RM) $(OBJS)
		@printf "Deleted \n"

fclean:	clean
		@printf "Deleting ...\n"
		@$(RM) $(NAME)
		@printf "Deleted\n"

re:				fclean all

.PHONY:		all clean fclean re valgrind
