/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:40:07 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/25 17:34:01 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

int main(int ac, char **av, char **envp)
{
    (void) av;
    (void) ac;
    (void) envp;
    char    *input;

    input = readline("$>Minishell ");
    while (input)
    {
        input = readline("$>Minishell ");
        if (strlen(input) > 0)
            add_history(input);
    }
    return (0);
}   