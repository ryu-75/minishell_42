/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:40:07 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/27 15:56:31 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

void    launch_minishell(t_token *token, t_lexer *lexer)
{
    char    *input;
    (void) token;
    (void) lexer;
    
    while (1)
    {
        input = readline("$>Minishell ");
        if (*input == 0 || ft_strlen(input) == 0)
            continue ;
        if (ft_strlen(input) > 0)
            add_history(input);
    }
}

void    init_all(t_token *token, t_lexer *lexer)
{
    t_token *tok;
    t_lexer *lex;

    tok = token;
    lex = lexer;
    init_token(tok);
    init_lexer(lex);
}

int main(int ac, char **av, char **envp)
{
    (void) av;
    (void) ac;
    (void) envp;
    t_token *token;
    t_lexer *lex;
    
    token = NULL;
    lex = NULL;
    init_all(token, lex);
    launch_minishell(token, lex);
    return (0);
}   