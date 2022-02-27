/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/27 03:57:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **envp, char *argv);
int open_files(t_data *data, char **argv);

int	main(int argc, char *argv[], char *envp[])
{
	char		*cmd;
	char		**command;
	pid_t		pid1;
	pid_t		pid2;
	pid_t		error;
	t_data		data;

	if (argc != 5)
	{
		perror("Invalid Number of Parameters");
		return (1);
	}
	if(open_files(&data, argv) != 0)
		return(1);
	if (pipe(data.fd) == -1)
	{
		perror("Error on opening pipe");
		return (1);
	}
	command = ft_split(argv[2], ' ');
	cmd = path(envp, command[0]);
	if (cmd == NULL)
	{
		perror("comand not exist");
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(data.infile, STDIN_FILENO);
		dup2(data.fd[1], STDOUT_FILENO);
		close(data.fd[1]);
		close(data.fd[0]);
		if (execve(cmd, command, NULL) == -1)
		{
			perror(cmd);
			return(127);
		}
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(data.fd[0], STDIN_FILENO);
		dup2(data.outfile, STDOUT_FILENO);
		dup2(data.outfile, STDOUT_FILENO);
		close(data.infile);
		close(data.fd[0]);
		close(data.fd[1]);
		command = ft_split(argv[3], ' ');
		cmd = path(envp, command[0]);
		if (cmd == NULL)
		{
			perror("comand not exist");
			return (1);
		}
		error = execve(cmd, command, NULL);
		printf("%d\n", error);
		if (execve(cmd, command, NULL) == -1)
		{
			perror(cmd);
			return(1);
		}
	}
	close(data.outfile);
	close(data.fd[0]);
	close(data.fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int open_files(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		perror(argv[1]);
		close(data->infile);
		return(1);
	}
	if(access(argv[1], R_OK) < 0)
	{
		perror(argv[1]);
		close(data->infile);
		return(1);
	}
	data->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile < 0)
	{
		perror(argv[4]);
		close(data->infile);
		close(data->outfile);
		return(1);
	}
	if(access(argv[4], R_OK) < 0)
	{
		perror(argv[1]);
		close(data->outfile);
		close(data->infile);
		return(1);
	}
	return (0);
}

char *path(char **envp, char *argv)
{
	int i;
	char *temp;
	char **path;
	char *command;

	i = 0;
	while(envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			temp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break;
		}
		i++;
	}
	i = 0;
	path = ft_split(temp, ':');
	free(temp);
	command = ft_strdup("");
	while(path[i])
	{
		temp = ft_strjoin(path[i], "/");
		free(path[i]);
		if (access(command, F_OK) != 0)
		{
			free(command);
			command = ft_strjoin(temp, argv);
		}
		free(temp);
		i++;
	}
	free(path);
	if (access(command, F_OK) == 0)
		return (command);
	free(command);
	return (NULL);
}
