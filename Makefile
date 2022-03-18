# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schung <schung@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 18:44:32 by schung            #+#    #+#              #
#    Updated: 2022/03/18 20:04:10 by schung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

NAME_B = philo_bonus

HEADER = philo/headers/philo.h

HEADER = philo_bonus/headers/philo_bonus.h

SRC = philo/philo.c \

SRC_B = philo_bonus/philo_bonus.c \

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS)

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

%.o: %.c $(HEADER)
	$(CC) -I $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I $(HEADER) $(OBJ) -o $(NAME)
	@echo "$(LMAGENTA)[INFO] [$(NAME)] created"

bonus: $(NAME_B)

$(NAME_B): $(OBJ_B)
	@$(CC) -I $(HEADER_B) $(OBJ_B) -o $(NAME_B)
	@echo "$(CYAN)[INFO] [$(NAME_B)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_B)
	@echo "$(YELLOW)[INFO] Removed [$(NAME)] objects"

fclean: clean
	@$(REMOVE) $(NAME) $(OBJ) $(NAME_B) $(OBJ_B)
	@echo "$(YELLOW)[INFO] [$(NAME)] and objects removed"

re: fclean all

.PHONY: all clean fclean re bonus

#COLOURS
NOCOLOR=\033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
LMAGENTA= \033[1;35m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
LIGHTGRAY=\033[0;37m
DARKGRAY=\033[1;30m
LIGHTRED=\033[1;31m
LIGHTGREEN=\033[1;32m
LIGHTBLUE=\033[1;34m
LIGHTPURPLE='\033[1;35m
LIGHTCYAN=\033[1;36m
WHITE=\033[1;37m
