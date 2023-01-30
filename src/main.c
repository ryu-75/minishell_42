/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:40:07 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/26 16:11:43 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

int main(int ac, char **av, char **envp)
{
    (void) av;
    (void) ac;
    (void) envp;
    char    *input;

    while (1)
    {
        input = readline("$>Minishell ");
        check_syntaxe(input);
        if (ft_strlen(input) > 0)
            add_history(input);
        free(input);
    }
    return (0);
}   