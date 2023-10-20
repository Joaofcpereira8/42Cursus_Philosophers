# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 12:56:32 by jofilipe          #+#    #+#              #
#    Updated: 2023/10/20 10:54:11 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread 
RM = rm -rf

SRCS =	mandatory/main.c\
		mandatory/ft_fnctns.c\
		mandatory/inits.c\
		mandatory/thread.c\
		mandatory/mutex.c\
		mandatory/routine.c\
		mandatory/utils.c\
		mandatory/mntrng.c\


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		clear
		echo "$(BLUE) _____  _     _ _                       _                   $(RESET)"
		echo "$(WHITE)|  __ \| |   (_) |                     | |                  $(RESET)"
		echo "$(BLUE)| |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ $(RESET)"
		echo "$(WHITE)|  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|$(RESET)"
		echo "$(BLUE)| |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \$(RESET)"
		echo "$(WHITE)|_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/$(RESET)"
		echo "$(BLUE)                                 | |                        $(RESET)"
		echo "$(WHITE)                                 |_|                        $(RESET)"
		echo ""
		echo "$(GREEN)Philosophers is ready to go!$(RESET)"



clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	echo "$(RED)Objects and executable files have been erased!$(RESET)"

re: fclean all

.SILENT:
