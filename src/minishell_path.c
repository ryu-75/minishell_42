/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:35:57 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/25 17:29:38 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

char    **retrieve_path(char **envp)
{
    int i;
    char    **paths;
    
    i = 0;
    while (!ft_strnstr(envp[i], "PATH", 4))
        i++;
    paths = ft_split(envp[i] + 5, ':');
    return (paths);
}