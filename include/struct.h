#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
    char    **envp;
    char    *env;
    struct s_env    *next;
}       t_env;

#endif