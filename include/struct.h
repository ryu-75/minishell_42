/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:38:23 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/27 12:56:34 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// type ---> what kind of token is (for example : number, identifying, operator, etc...)
// value ---> Contents the value associated with the token (for example : a string that makes up the number or identifier)
typedef struct  s_token
{
    int type;
    char    value;
}       t_token;

// input ---> A string containing the entry to be analyzed
// position ---> Indicates the current position in the entry
// read_position ---> Indicates the next position to be read
// ch ---> Contains the currently read character
typedef struct  s_lexer
{
    char    *input;
    int position;
    int read_position;
    char    ch;
}       t_lexer;

#endif