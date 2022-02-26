/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/26 00:06:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	char	*cmd;
	char	**command;
	int		pid1;
	int		pid2;
	int		*fd;
	int		infile;
	int		outfile;
	int		error;

	if ( argc != 5)
	{
		perror("Invalid Number of Parameters");
		return (1);
	}
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		close(infile);
		return(1);
	}
	if(access(argv[1], R_OK) < 0)
	{
		perror(argv[1]);
		close(infile);
		return(1);
	}
	outfile = open(argv[4], O_RDWR);
	if (outfile < 0)
	{
		perror(argv[4]);
		close(infile);
		close(outfile);
		return(1);
	}
	if(access(argv[4], R_OK) < 0)
	{
		perror(argv[1]);
		close(outfile);
		close(infile);
		return(0);
	}
	fd = malloc (sizeof(int) * 2);
	fd[0] = 0;
	fd[1] = 0;
	if (pipe(fd) == -1)
	{
		perror("Error on opening pipe");
		return (1);
	}
	command = ft_split(argv[2], ' ');
	cmd = ft_strjoin("/usr/bin/", command[0]);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(cmd, command, NULL) == -1)
		{
			perror(cmd);
			return(127);
		}
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(infile);
		close(fd[0]);
		close(fd[1]);
		command = ft_split(argv[3], ' ');
		cmd = ft_strjoin("/usr/bin/", command[0]);
		error = execve(cmd, command, NULL);
		printf("%d\n", error);
		if (execve(cmd, command, NULL) == -1)
		{
			perror(cmd);
			return(127);
		}
	}
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
