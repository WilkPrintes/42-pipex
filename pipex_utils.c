/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:13:54 by coder             #+#    #+#             */
/*   Updated: 2022/02/28 01:41:02 by coder            ###   ########.fr       */
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
		perror(argv[4]);
		close(data->infile);
		close(data->outfile);
		return (1);
	}
	if (access(argv[4], R_OK) < 0)
	{
		perror(argv[1]);
		close(data->outfile);
		close(data->infile);
		return (1);
	}
	return (0);
}

int	validations(int argc, t_data *data, char **argv)
{	
	if (argc != 5)
	{
		perror("Invalid Number of Parameters");
		return (1);
	}
	if (open_files(data, argv) != 0)
		return (1);
	if (pipe(data->fd) == -1)
	{
		perror("Error on opening pipe");
		return (1);
	}
	return (0);
}

int	open_files(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile < 0)
	{
		perror(argv[1]);
		close(data->infile);
		return (1);
	}
	if (access(argv[1], R_OK) < 0)
	{
		perror(argv[1]);
		close(data->infile);
		return (1);
	}
	if (open_outfile(data, argv) != 0)
		return (1);
	return (0);
}
