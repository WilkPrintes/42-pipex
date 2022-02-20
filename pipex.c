/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:39:41 by wprintes          #+#    #+#             */
/*   Updated: 2022/02/20 04:27:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[])
{
	char	*cmd;
	char	*argV[] = {argv[1], NULL};
	char	*path;

	if (argc <= 1)
	{
		printf("numero de argumentos inválidos :/\n");
		return (1);
	}
	path = ft_strjoin("","/usr/bin/");
	cmd = ft_strjoin(path, argv[1]);
	if (execve(cmd, argV, NULL) == -1)
		perror("Nope\n");
	printf("nope :/\n");
}