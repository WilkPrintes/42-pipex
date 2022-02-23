/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:40:19 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/22 23:40:38 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char    **ft_split(char *buffer, char separator);
char    *ft_strdup(char *buffer, int stop);
