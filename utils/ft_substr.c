/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:34 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 16:29:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	counter;
	size_t	s_len;

	if (!s)
		return (NULL);
	counter = 0;
	s_len = ft_strlen((char *)s);
	if (start > ft_strlen((char *)(s)))
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	result = ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	while (counter < len && s[counter + start] != '\0')
	{
		result[counter] = s[counter + start];
		counter++;
	}
	result[counter] = '\0';
	return (result);
}
