/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:43:53 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/08/09 19:20:08 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex pipex, char **argv, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_wout_free("Problem on opening file", 1);
	if ((dup2(fd, STDIN_FILENO)) == -1)
		exit_wout_free("problem on dup function", 1);
	if ((dup2(pipex.fds[1], STDOUT_FILENO)) == -1)
		exit_wout_free("Problem on pud function", 1);
	if (close(fd) == -1)
		exit_wout_free("Problem on close function", 1);
	if ((close(pipex.fds[0]) == -1))
		exit_wout_free("Problem on close function", 1);
	if ((close(pipex.fds[1])) == -1)
		exit_wout_free("Problem on close function", 1);
	ft_execute(pipex, argv[2], envp);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_pipex pipex, char **argv, char **envp)
{
	int	fd;
	int	status;

	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		exit_wout_free("child process exited with fail", 1);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_wout_free("Problem on opening file", 1);
	if (access(argv[4], F_OK))
		exit_wout_free("outfile is not exist", 1);
	if (access(argv[4], W_OK))
		exit_wout_free("outfile is not writtable", 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit_wout_free("Problem on dup2 function", 1);
	if (dup2(pipex.fds[0], STDIN_FILENO) == -1)
		exit_wout_free("Problem on dup2 function", 1);
	if (close(fd) == -1)
		exit_wout_free("Problem on close function", 1);
	if (close(pipex.fds[0]) == -1)
		exit_wout_free("Problem on close function", 1);
	if (close(pipex.fds[1]) == -1)
		exit_wout_free("Problem on close function", 1);
	ft_execute(pipex, argv[3], envp);
}
