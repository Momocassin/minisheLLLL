# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 07:30:46 by edvicair          #+#    #+#              #
#    Updated: 2023/01/14 20:11:40 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Wextra -Werror -g
RL = -lreadline
INC = minishell.h
SRC = Libft/ft_lstclear.c Libft/ft_lstdelone.c Libft/ft_atoi.c Libft/ft_isalnum.c minishell.c lib.c split.c INIT/init_env.c INIT/init_tok.c BUILT/cd.c BUILT/pwd.c BUILT/export.c BUILT/export_sort.c BUILT/env.c BUILT/unset.c BUILT/echo.c BUILT/exit.c ft_free.c PARSING/parsing.c PARSING/tokenizator.c PARSING/utils_parsing.c PARSING/utils_parsing2.c EXEC/child.c EXEC/exec.c INIT/init_redir.c PARSING/syntax.c PARSING/expand.c
OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(RL) #-fsanitize=address
	
%.o: %.c
	gcc -g -o $@ -c $< 

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
