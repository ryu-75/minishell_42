NAME                                            = minishell
EXEC                                            = $(NAME)

# *********************** DIRECTORY ************************************* #
SRCS_DIR                                        = src/
OBJ_DIR                                         = obj/
INC												= -I ./include -I ./libft

# *********************** SOURCES **************************************** #
SRC												= main.c					\
													minishell_utils.c		\
													minishell_path.c		\
													minishell_quote.c

SRCS											= $(addprefix $(SRCS_DIR), $(SRC))

# *********************** OBJECT ***************************************** #
OBJ												= $(SRC:.c=.o)
OBJS											= $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o									: $(SRCS_DIR)%.c
													@mkdir -p $(OBJ_DIR)
													@$(CC) $(CFLAGS) -c $< -o $@

# *********************** COMPILATION ************************************ #
CC												= clang

$(EXEC)											: libft/libft.a $(OBJS)
													@$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline $(INC) $(LIB) $(OBJS) -L libft -lft -o $(EXEC)

# ********************** FLAGS ******************************************* #
CFLAGS											= -g -Wall -Wextra -Werror

all												: $(EXEC)

libft/libft.a									:
													@make -C libft

clean											: 
													@rm -rf $(OBJ_DIR)
													make clean -C libft

fclean											: clean
													@rm -f $(EXEC)
													make fclean -C libft

re												: fclean
													@make all

.PHONY											= all clean fclean re