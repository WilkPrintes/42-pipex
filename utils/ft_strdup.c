/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:20:45 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 17:08:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *src)
{
	char	*result;

	result = ft_calloc(sizeof(char), ft_strlen((char *)src) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, src, ft_strlen((char *) src) + 1);
	return (result);
}
