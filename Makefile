NAME                                            = minishell
EXEC                                            = $(NAME)

# *********************** DIRECTORY ************************************* #
SRCS_DIR                                        = src/
OBJ_DIR                                         = obj/
INC												= -I ./include -I ./libft

GNL_DIR											= get_next_line_42Project/src/
GNL_OBJDIR										= get_next_line_42Project/obj/
LIB												= -I ./get_next_line_42Project/include/

# *********************** SOURCES **************************************** #
SRC												= main.c					\
													minishell_utils.c		\
													minishell_path.c		

GNL_SRC											= get_next_line_bonus.c	\


SRCS											= $(addprefix $(SRCS_DIR), $(SRC))
GNL_SRCS										= $(addprefix $(GNL_DIR)? $(GNL_SRC))

# *********************** OBJECT ***************************************** #
OBJ												= $(SRC:.c=.o)
OBJS											= $(addprefix $(OBJ_DIR), $(OBJ))
GNL_OBJ											= $(GNL_SRC:.c=.o)
GNL_OBJS										= $(addprefix $(GNL_OBJDIR), $(GNL_OBJ))

$(OBJ_DIR)%.o									: $(SRCS_DIR)%.c
													@mkdir -p $(OBJ_DIR)
													@$(CC) $(CFLAGS) -c $< -o $@

$(GNL_OBJDIR)%.o								: $(GNL_DIR)%.c
												@mkdir -p $(GNL_OBJDIR)
													@$(CC) $(CFLAGS) -c $< -o $@

# *********************** COMPILATION ************************************ #
CC												= clang

$(EXEC)											: libft/libft.a $(OBJS) $(GNL_OBJS)
													@$(CC) $(CFLAGS) -L/usr/local/lib -I/usr/local/include -lreadline $(INC) $(LIB) $(OBJS) $(GNL_OBJS)  -L libft -lft -o $(EXEC)

# ********************** FLAGS ******************************************* #
CFLAGS											= -g -Wall -Wextra -Werror

all												: $(EXEC)

libft/libft.a									:
													@make -C libft

clean											: 
													@rm -rf $(OBJ_DIR) $(GNL_OBJDIR)
													make clean -C libft

fclean											: clean
													@rm -f $(EXEC)
													make fclean -C libft

re												: fclean
													@make all

.PHONY											= all clean fclean re