#ifndef FUNCTION_H
# define FUNCTION_H

// ---------------- INCLUDE ------------------- //

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
# include "../libft/GNL/include/get_next_line_bonus.h"
# include "../libft/libft.h"
#include "macro.h"
#include "struct.h"

// ....................... FUNCTIONS ....................  //

int ft_getline(char **lineptr, size_t *n, FILE *stream);
char    **retrieve_path(char **envp);

// ....................... PARSER ....................... //
void    empty_line(char *s);

// ....................... SYNTAXE ...................... //
void    simple_syntaxe(char *s);
void    rafter(char *s);
void    check_syntaxe(char *s);
void    slash(char *s);
void    syntax_error(char *s);
#endif