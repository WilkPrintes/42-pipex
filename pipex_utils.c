/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:13:54 by coder             #+#    #+#             */
/*   Updated: 2022/03/13 01:13:48 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			temp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			break ;
		}
		i++;
	}
	return (temp);
}

int	open_outfile(t_data *data, char **argv)
{
	data->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile < 0)
	{
		perror("Error");
		close(data->infile);
		close(data->outfile);
		return (EXIT_FAILURE);
	}
	data->error = access(argv[4], R_OK);
	if (data->error < 0)
	{
		perror("Error");
		close(data->outfile);
		close(data->infile);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	validations(int argc, t_data *data, char **argv)
{	
	if (argc != 5)
	{
		ft_putstr_fd("Invalid Number of Parameters", 2);
		return (EXIT_FAILURE);
	}
	if (open_files(data, argv) != 0)
		return (EXIT_FAILURE);
	if (pipe(data->fd) == -1)
	{
		ft_putstr_fd ("Error on opening pipe", 2);
		return (EXIT_FAILURE);
	}
	return (0);
}

int	open_files(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		perror("Error");
		close(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	data->error = access(argv[1], R_OK);
	if (data->error < 0)
	{
		perror("Error");
		close(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	if (open_outfile(data, argv) != 0)
		return (EXIT_FAILURE);
	return (0);
}

void	free_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (data->command[i])
		free (data->command[i++]);
	free (data->command);
	free (data->cmd);
}
