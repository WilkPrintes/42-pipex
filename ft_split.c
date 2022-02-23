/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:56:07 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/23 00:02:56 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **ft_split(char *buffer, char separator)
{
    int index;
    int len;
    int find_s;
    char *temp;
    char **result;
    int position;

    position = 0;
    index = 0;
    len = 0;
    find_s = 1;
    while (len < ft_strlen(buffer))
    {
        if (buffer[len] == separator)
            find_s++;
        len++;
    }
    result = malloc (sizeof (char *) * find_s);
    len = 0;
    while(index < find_s)
    {   
        while (len < ft_strlen(buffer) && buffer[len] != separator)
        {
            len++;
        }
        temp = ft_strdup(buffer + position, len - position);
        result[index] = ft_strdup(temp, len - position);
        free(temp);
        if (index + 1 != find_s)
            len++;
        index++;
        position = len;
    }
    return (result);
}