/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 03:17:21 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 00:02:46 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join(char *s1_val, char *s2_val, char *result);

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	char	*s1_val;
	char	*s2_val;

	if (!s1 || !s2)
		return (NULL);
	s1_val = (char *)s1;
	s2_val = (char *)s2;
	result = malloc(sizeof(char) * (ft_strlen(s1_val) + ft_strlen(s2_val)) + 1);
	if (result == NULL)
		return (NULL);
	result = join(s1_val, s2_val, result);
	return (result);
}

char	*join(char *s1_val, char *s2_val, char *result)
{
	size_t	counter;

	counter = 0;
	while (s1_val[counter] != '\0')
	{
		result[counter] = s1_val[counter];
		counter++;
	}
	counter = 0;
	while (s2_val[counter] != '\0')
	{
		result[ft_strlen(s1_val) + counter] = s2_val[counter];
		counter++;
	}
	result[ft_strlen(s1_val) + counter] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
