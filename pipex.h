/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:40:19 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/27 03:52:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_data
{
	pid_t		infile;
	pid_t		outfile;
	pid_t		fd[2];
	pid_t		pid1;
	pid_t		pid2;

}t_data;

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int     ft_strncmp(const char *str1, const char *str2, size_t n);

