#      NAME       #
NAME		=	philo

#      FLAGS      #

CC			=	cc -pthread
FLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -rf

#       MANDATORY    #

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
		@printf "$(GREEN)Philophers Compiled 😎\n"

all: $(NAME)

clean:
		@printf "$(YELLOW)Deleting the Philophers Objects...\n"
		@$(RM) $(OBJS)
		@printf "$(GREEN)Philophers Objects Deleted 😎 🗑\n"

fclean:	clean
		@printf "$(YELLOW)Deleting Philophers 🔪...\n"
		@$(RM) $(NAME)
		@printf "$(GREEN)Philophers Deleted 😎 🗑 💀\n"

re:				fclean all

valgrind: all
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --error-limit=no --gen-suppressions=all --track-origins=yes  --log-file=minishell.log ./philo 5 200 200 200

.PHONY:		all clean fclean re valgrind


GREEN=\033[0;32m
YELLOW=\033[0;33m