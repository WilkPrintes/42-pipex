/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:19:56 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/14 15:12:38 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*str1_char;
	unsigned char	*str2_char;
	int				result;
	size_t			counter;

	str1_char = (unsigned char *) str1;
	str2_char = (unsigned char *) str2;
	result = 0;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n && *str1_char != '\0' && *str2_char != '\0')
	{
		if (*str1_char != *str2_char)
		{
			result = *str1_char - *str2_char;
			return (result);
		}
		counter++;
		str1_char++;
		str2_char++;
	}
	if (counter < n && (*str1_char == '\0' || *str2_char == '\0'))
		result = *str1_char - *str2_char;
	return (result);
}
