/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes < wprintes@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/23 04:26:09 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	char	*cmd;
	char	**argV;
	char	*path;
	int		pid;
	int		status;
	int		file;
	int		file2;
	int		*fd;

	fd = malloc (sizeof (int) * 2);
	fd[0] = 0;
	fd[1] = 0;
	if (pipe(fd) == -1)
	{
		printf("Erro in Pipe\n");
		return (1);
	}
	pid = fork();
	file = open("ping_resutls.txt", O_WRONLY | O_CREAT, 0777);
	if (file == -1)
		return (1); 
	file2 = dup2(file, STDOUT_FILENO);
	close(file);
	argV = ft_split(argv[1], ' ');
	if (argc <= 1)
	{
		printf("numero de argumentos inválidos :/\n");
		return (1);
	}
	path = ft_strjoin("","/usr/bin/");
	cmd = ft_strjoin(path, argV[0]);
	if (pid == 0)
	{
		if (execve(cmd, argV, NULL) == -1)
			perror("Nope\n");
	}
	else
	{
		waitpid(pid, &status, 0);
		argV = ft_split(argv[2], ' ');
		cmd = ft_strjoin(path, argV[0]);
		if (execve(cmd, argV, NULL) == -1)
			perror("Nope\n");
		free(argV);
	}
}
