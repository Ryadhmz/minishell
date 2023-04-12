CC = @gcc

NAME = minishell

CFLAGS =

SRCS = 	main.c \
			utils/ft_split.c \
			utils/ft_split_boost.c \
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
			parsing/ft_strtrim.c \
			check_cmd/check_cmd.c \
			utils/ft_strcmp.c \
			built-in/echo.c \
			utils/while_carac.c \
			linked_list/free_next.c \
			utils/check_last_carac.c \
			parsing/remove_carac.c	\
			parsing/check_carac.c \
			parsing/check_carac_two.c \
			linked_list/free_list.c \
			signal/signal.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
			
LIB = -lreadline -L /Users/$$USER/.brew/opt/readline/lib

INC = -I /Users/$$USER/.brew/opt/readline/include

OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} ${INC} -g3 -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

all: $(NAME)

clean :
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean