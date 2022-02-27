/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:40:38 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 17:09:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size == 0)
	{
		return (ft_strlen((char *) src));
	}
	while (counter < size - 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		counter++;
	}
	*dst = '\0';
	return (ft_strlen ((char *)(src - counter)));
}
