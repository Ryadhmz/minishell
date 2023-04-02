MINISHELL = main.c utils/ft_split.c utils/ft_strlen.c utils/search_path.c
			
CC = @gcc

FLAGS = -Wall -Werror -Wextra

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