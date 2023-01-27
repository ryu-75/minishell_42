/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:38:23 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/27 15:20:28 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_token
{
    WORD = -1,
    SLASH = '/',
    MINUS = '-',
    PLUS = '+',
    S_QUOTE = '\'',
    D_QUOTE = '\"',
    AMPER = '&',
    DOLLAR = '$',
    SHARP = '#',
    SUP = '>',
    INF = '<'
}       e_token;

// type ---> what kind of token is (for example : number, identifying, operator, etc...)
// value ---> Contents the value associated with the token (for example : a string that makes up the number or identifier)
typedef struct  s_token
{
    int type;
    char    content;
    e_token val;
}       t_token;

// input ---> A string containing the entry to be analyzed
// pos ---> Indicates the current position in the entry
// rd_pos ---> Indicates the next position to be read
// ch ---> Contains the currently read character
typedef struct  s_lexer
{
    char    *input;
    int pos;
    int rd_pos;
    char    ch;
    struct s_lexer  *next;
}       t_lexer;

#endif