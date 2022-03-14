/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wprintes <wprintes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:53:45 by wprintes          #+#    #+#             */
/*   Updated: 2022/03/14 15:15:28 by wprintes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(char **argv, char *envp[], t_data *data);
void	second_command(char **argv, char *envp[], t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc == 5)
	{
		if (pipe(data.fd) == -1)
			error();
		data.pid1 = fork();
		if (data.pid1 == -1)
			error();
		if (data.pid1 == 0)
			first_command(argv, envp, &data);
		else
		{
			waitpid(data.pid1, NULL, 0);
			second_command(argv, envp, &data);
		}
		return (0);
	}
	else
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit (EXIT_FAILURE);
	}
}

void	first_command(char **argv, char *envp[], t_data *data)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error();
	dup2(data->fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(data->fd[0]);
	command(argv[2], envp, data);
}

void	second_command(char **argv, char *envp[], t_data *data)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(data->fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(data->fd[1]);
	command(argv[3], envp, data);
}
