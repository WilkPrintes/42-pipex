/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:30:52 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/23 00:02:50 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_strdup(char *buffer, int stop)
{
    int index;
    char *result;

    if (ft_strlen(buffer) < stop)
        return (NULL);
    result = malloc (sizeof(char) * (stop + 1));
    index = 0;
    while (index < stop)
    {
        result[index] = buffer[index];
        index++;
    }
    result[index] = '\0';
    return (result);
}