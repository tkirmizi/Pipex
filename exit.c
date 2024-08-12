/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:03:58 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/08/11 14:31:44 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_wout_free(const char *message, int	i)
{
	perror(message);
	exit(i);
}

void	exit_w_free(const char *message, t_pipex pipex, int j)
{
	int	i;

	i = 0;
	if (!(pipex.path))
		free(pipex.path);
	if (!(pipex.command))
		free(pipex.command);
	if (!(pipex.path_ptr))
	{
		i = 0;
		while (pipex.path_ptr[i])
			free(pipex.path_ptr[i++]);
		free(pipex.path_ptr);
	}
	if (!(pipex.command_ptr[i]))
	{
		i = 0;
		while (pipex.command_ptr[i])
			free(pipex.command_ptr[i++]);
		free(pipex.command_ptr);
	}
	perror(message);
	exit(j);
}
