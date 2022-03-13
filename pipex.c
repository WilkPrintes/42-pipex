/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/13 01:15:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **envp, char *argv);
int		open_files(t_data *data, char **argv);
int		command1(t_data *data);
int		command2(t_data *data);
int		error(t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (validations(argc, &data, argv) != 0)
		return (1);
	data.command = ft_split(argv[2], ' ');
	data.cmd = path(envp, data.command[0]);
	if (data.cmd == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		free_matrix(&data);
	}
	else
	{
		data.error = command1(&data);
		if (data.error != 0)
			return (data.error);
	}
	data.command = ft_split(argv[3], ' ');
	data.cmd = path(envp, data.command[0]);
	if (data.cmd == NULL)
		return (error(&data));
	data.error = command2(&data);
	if (data.error != 0)
		return (data.error);
	waitpid(data.pid1, &data.error, 0);
	waitpid(data.pid2, &data.error, 0);
	return (0);
}

int	error(t_data *data)
{
	free_matrix(data);
	ft_putstr_fd("command not exist\n", 2);
	return (127);
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
			free_matrix(data);
			ft_putstr_fd(strerror(data->error), 2);
			return (data->error);
		}
	}
	free_matrix(data);
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

	}
	else
	{
		printf("%d\n", data->error);
	}
	close(data->outfile);
	close(data->fd[0]);
	close(data->fd[1]);
	free_matrix(data);
	return (0);
}

char	*path(char **envp, char *argv)
{
	t_path	path;
	int		i;

	i = 0;
	path.temp = get_path(envp);
	path.path = ft_split(path.temp, ':');
	free(path.temp);
	path.command = ft_strdup("");
	while (path.path[i])
	{
		path.temp = ft_strjoin(path.path[i], "/");
		free(path.path[i]);
		if (access(path.command, F_OK) != 0)
		{
			free(path.command);
			path.command = ft_strjoin(path.temp, argv);
		}
		free(path.temp);
		i++;
	}
	free(path.path);
	if (access(path.command, F_OK) == 0)
		return (path.command);
	free(path.command);
	return (NULL);
}
