/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:56:20 by nlorion           #+#    #+#             */
/*   Updated: 2023/01/25 23:40:02 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/function.h"

int ft_getline(char **lineptr, size_t *n, FILE *stream)
{
   static char line[256];
   char  *ptr;
   unsigned int   len;

   if (lineptr == NULL || n == NULL)
      return -1;
   if (ferror (stream))
      return -1;   
   if (feof(stream))
      return -1;
   fgets(line,256,stream); 
   ptr = ft_strchr(line,'\n');   
   if (ptr)
      *ptr = '\0'; 
   len = ft_strlen(line);
   if ((len + 1) < 256)
   {
      ptr = realloc(*lineptr, 256);
      if (ptr == NULL)
         return(-1);
      *lineptr = ptr;
      *n = 256;
   }   
   strcpy(*lineptr,line); 
   return(len);
}
