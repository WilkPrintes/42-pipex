/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 16:30:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			counter;
	char			*str_p;

	counter = 0;
	str_p = str;
	while (counter != n)
	{
		str_p[counter] = '\0';
		counter++;
	}
}
