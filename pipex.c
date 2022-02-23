/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/23 06:12:53 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	char	*cmd;
	char	**argV;
	char	*path;
	int *fd;
	int pid1;
	int pid2;
	int file;
	int file2;

	if (argc != 5)
	{
		printf("numero de argumentos inválidos :/\n");
		return (1);
	}
	file = open(argv[1], O_RDWR);
	if (file == -1)
	{
		perror(argv[4]);
		return(1);
	}
	file2 = open(argv[4], O_RDWR);
	if (file2 == -1)
	{
		perror(argv[4]);			
		return(1);
	}
	dup2(fd[0], STDIN_FILENO);
	path = ft_strjoin("","/usr/bin/");
	fd = malloc (sizeof(int) * 2);
	fd[0] = 0;
	fd[1] = 0;
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return(2);
	if (pid1 == 0)
	{
		argV = ft_split(argv[2], ' ');
		cmd = ft_strjoin(path, argV[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd, argV, NULL) == -1)
		{
			dup2(file2, STDOUT_FILENO);
			perror(cmd);
			return(1);
		}
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		return (3);
	}
	if (pid2 == 0)
	{
		close(fd[0]);
		close(fd[1]);
		dup2(file2, STDOUT_FILENO);
		argV = ft_split(argv[3], ' ');
		cmd = ft_strjoin(path, argV[0]);
		if (execve(cmd, argV, NULL) == -1)
		{
			perror(cmd);
			return(1);
		}
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
