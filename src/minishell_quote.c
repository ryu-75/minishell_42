/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:37:16 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/26 18:40:21 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

// Skip the prompt name
void    empty_line(char *s)
{
    int i;

    i = 0;
    while (s[i] && ft_strnstr(s, "Minishell ", 9))
        i++;
}

// Check if we any syntax match with those write in condition
void    simple_syntaxe(char *s)
{
    int i;

    i = 0;
    if (s[i] == '!' || s[i] == '#' || s[i] == ':' || s[i] == 32 || s[i] == '\t')
        readline("$>Minishell ");
    else if (s[i] == '-')
        ft_putstr_fd("bash: -: command not found\n", 0);
}

// For the left, we writing an error message if we have a simple or multiple '>' and '<'
void    rafter(char *s)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    if ((s[i] == '>' || s[i] == '<') && len < 3)
        ft_putstr_fd("bash: syntax error near unexpected token 'newline'\n", 0);
    else if ((s[i] == '>' || s[i] == '<') && s[i + 1] == ' ')
    {
        if (s[i] == '>')
            ft_putstr_fd("bash: syntax error near unexpected token '>'\n", 0);
        else if (s[i] == '<')
            ft_putstr_fd("bash: syntax error near unexpected token '<'\n", 0);
    }
    else if ((s[i] == '>' || s[i] == '<') && len > 2)
    {
        while (s[i] != 0)
        {
            if (s[i] == '|')
            {
                ft_putstr_fd("bash: syntax error near unexpected token ", 0);
                ft_putstr_fd(&s[i], 0);
                write(1, "\n", 1);
                return ;
            }
            i++;
        }
        i = 0;
        if (s[i] == '>')
            ft_putstr_fd("bash: syntax error near unexpected token `>>'\n", 0);
        else if (s[i] == '<')
            ft_putstr_fd("bash: syntax error near unexpected token `<<'\n", 0);
    }
}

// Check if we have a slash or many slash in arguments and return an error message
void    slash(char *s)
{
    int i;
    int len;
    
    i = 0;
    len = ft_strlen(s);
    if (s[i] == '/' && len > 1)
    {
        write(1, "bash: ", 6);
        ft_putstr_fd(&s[i], 0);
        ft_putstr_fd(": Is a directory\n", 0);
    }
    else if (s[i] == '/' && len == 1)
        ft_putstr_fd("bash: /: Is a directory\n", 0);
    else if (s[i] == '/' && s[i] == '.' && len > 1)
    {
        write(1, "bash: ", 6);
        ft_putstr_fd(&s[i], 0);
        ft_putstr_fd(": Is a directory\n", 0);
    }        
}

// Check the different syntax error
void    syntax_error(char *s)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    if ((s[0] == '|' && len == 1) || s[i + 1] == 32)
        ft_putstr_fd("bash: syntax error near unexpected token '|'\n", 0);
    else if (s[i] == '|' && len > 1)
        ft_putstr_fd("bash: syntax error near unexpected token '||'\n", 0);
    else if (s[i] == '&' && len == 1)
        ft_putstr_fd("bash: syntax error near unexpected token '&'\n", 0);
    else if (s[i] == '&' && len > 1)
        ft_putstr_fd("bash: syntax error near unexpected token '&&'\n", 0);
}

// Return all errors syntax functions
void    check_syntaxe(char *s)
{
    empty_line(s);
    syntax_error(s);
    simple_syntaxe(s);
    rafter(s);
    slash(s);
}