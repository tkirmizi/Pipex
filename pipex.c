/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:56:00 by taha              #+#    #+#             */
/*   Updated: 2024/08/11 14:55:22 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		arg_check_frw(argv);
		if (pipe(pipex.fds) == -1)
			exit_wout_free("pipe function problem", 1);
		pipex.pid = fork();
		if (pipex.pid < 0)
			exit_wout_free("fork function problem", 1);
		if (pipex.pid == 0)
		{
			child_process(pipex, argv, envp);
		}
		parent_process(pipex, argv, envp);
	}
	else
		exit_wout_free("Not enough arguments", 1);
}
