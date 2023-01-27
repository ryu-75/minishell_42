/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:55:56 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/27 15:54:12 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

void    init_token(t_token *token)
{
    token = malloc(sizeof(t_token));
    if (!token)
        return ;
    token->type = 0;
    token->content = 0;
}

void    init_lexer(t_lexer *lexer)
{
    lexer = malloc(sizeof(t_lexer));
    if (!lexer)
        return ;
    lexer->pos = 0;
    lexer->rd_pos = 0;
    lexer->ch = 0;
}

void    new_token(char *str, char *type)
{
    t_token *tok;
    tok = malloc(sizeof(t_token));
    tok->val = type;
    
}

void    skip_whitespace(char *s)
{
    int i;

    i = 0;
    while (s[i] == 32 || s[i] == '\n' || s[i] == '\t' || s[i] == '\r')
        i++;
}

void    read_string(t_lexer *lexer)
{
    t_lexer *lex;
    
    lex = lexer;
    while (lex->input[lex->pos] != 0)
    {
        if (lex->pos >= (int)ft_strlen(lex->input))
            lex->ch = 0;
        else
            lex->ch = lex->input[lex->pos];
        lex->pos++;
    }
}