/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:40:35 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 17:10:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *str, int c)
{
	char	s1;

	s1 = c;
	while (*str != '\0')
	{
		if (*str == s1)
			return ((char *) str);
		str++;
	}
	if (s1 == '\0')
		return ((char *) str);
	return (NULL);
}
