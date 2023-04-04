MINISHELL = main.c \
			utils/ft_split.c \
			utils/ft_split_boost.c \
			utils/ft_strlen.c \
			utils/search_path.c \
			built-in/pwd.c \
			built-in/env.c \
			linked_list/ft_dblstadd_back.c \
			linked_list/ft_dblstlast.c \
			linked_list/ft_dblstnew.c \
			linked_list/ft_db_first_node.c \
			parsing/parsing.c \
			linked_list/ft_pop.c \
			linked_list/print_lst.c \
			parsing/arg_to_list.c \
			parsing/ft_strtrim.c
			
CC = @gcc

FLAGS = -lreadline -Wall -Werror -Wextra

MINISHELL_NAME = minishell

MINISHELL_SRC = $(MINISHELL)

MINISHELL_OBJS = $(MINISHELL_SRC:.c=.o)

all: $(MINISHELL_NAME)

minishell: $(MINISHELL_OBJS)
	@$(CC) $(FLAGS) $(MINISHELL_OBJS) -o $(MINISHELL_NAME)

bonus: all

clean:
	@rm -rf $(MINISHELL_OBJS)

fclean: clean
	@rm -rf $(MINISHELL_NAME)

re: fclean all