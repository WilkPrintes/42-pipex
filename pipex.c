/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/28 01:53:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **envp, char *argv);
int		open_files(t_data *data, char **argv);
int		command1(t_data *data);
int		command2(t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (validations(argc, &data, argv) != 0)
		return (1);
	data.command = ft_split(argv[2], ' ');
	data.cmd = path(envp, data.command[0]);
	if (data.cmd == NULL)
	{
		ft_putstr_fd("comand not exist\n", 2);
		return (127);
	}
	data.error = command1(&data);
	if (data.error != 0)
		return (data.error);
	data.command = ft_split(argv[3], ' ');
	data.cmd = path(envp, data.command[0]);
	if (data.cmd == NULL)
	{
		ft_putstr_fd("comand not exist\n", 2);
		return (127);
	}
	data.error = command2(&data);
	if (data.error != 0)
		return (data.error);
	waitpid(data.pid1, &data.error, 0);
	waitpid(data.pid2, &data.error, 0);
	return (0);
}

int	command1(t_data *data)
{
	data->pid1 = fork();
	if (data->pid1 == 0)
	{
		dup2(data->infile, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[1]);
		close(data->fd[0]);
		data->error = execve(data->cmd, data->command, NULL);
		if (data->error == -1)
		{
			free(data->command);
			free(data->cmd);
			perror(data->cmd);
			return (data->error);
		}
	}
	free(data->command);
	free(data->cmd);
	return (0);
}

int	command2(t_data *data)
{
	data->pid2 = fork();
	if (data->pid2 == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
		dup2(data->outfile, STDOUT_FILENO);
		close(data->infile);
		close(data->fd[0]);
		close(data->fd[1]);
		data->error = execve(data->cmd, data->command, NULL);
		if (execve(data->cmd, data->command, NULL) == -1)
		{
			perror(data->cmd);
			return (data->error);
		}
	}
	close(data->outfile);
	close(data->fd[0]);
	close(data->fd[1]);
	free(data->command);
	free(data->cmd);
	return (0);
}

char	*path(char **envp, char *argv)
{
	int		i;
	char	*temp;
	char	**path;
	char	*command;

	i = 0;
	path = ft_split(get_path(envp), ':');
	command = ft_strdup("");
	while (path[i])
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
