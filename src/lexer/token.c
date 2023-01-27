/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:55:56 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/27 13:04:29 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/function.h"

void    init_token(t_token *token)
{
    token = malloc(sizeof(t_token));
    if (!token)
        return ;
    token->type = 0;
    token->value = 0;
}

void    skip_whitespace(char *s)
{
    int i;

    i = 0;
    while (s[i] == 32 || s[i] == '\n' || s[i] == '\t' || s[i] == '\r')
        i++;
}

