#ifndef FUNCTION_H
# define FUNCTION_H

// ........................... INCLUDE ............................... //

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/GNL/get_next_line_bonus.h"
# include "../libft/libft.h"
# include "struct.h"

// ........................... INIT ............................... //

void    init_token(t_token *token);
void    init_lexer(t_lexer *lex);

// ........................ LEXER ................................. //

void    skip_prompt(char *str);
void    read_string(t_lexer *lexer);


int ft_getline(char **lineptr, size_t *n, FILE *stream);
char    **retrieve_path(char **envp);

#endif