/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:58:01 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/08/11 14:53:09 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_check_frw(char **argv)
{
	if (access(argv[1], F_OK))
		exit_wout_free("infile is not exist", 1);
	if (access(argv[1], R_OK))
		exit_wout_free("problem on reading infile", 126);
}

// void	ft_execute(t_pipex pipex, char *argv, char **envp)
// {
// 	int	i;

// 	i = -1;
// 	while (envp[++i])
// 	{
// 		if (!(ft_strncmp(envp[i], "PATH=", 5)))
// 			break ;
// 	}
// 	if (!(envp[i]))
// 		exit_wout_free("Problem on finding PATH in envp", 1);
// 	pipex.command_ptr = ft_split(argv, ' ');
// 	pipex.command = ft_strdup(pipex.command_ptr[0]);
// 	pipex.path = ft_strdup(envp[i] + 5);
// 	pipex.path_ptr = ft_split(pipex.path, ':');
// 	pipex_join(pipex);
// 	ft_execute_2(pipex, envp);
// }

void	ft_execute(t_pipex pipex, char *argv, char **envp)
{
	int	j;
	int	i;

	j = 0;
	if ((ft_strrchr(argv, '/')) != NULL)
	{
		pipex.path = ft_strdup(argv);
		j = 2147483647;
	}
	else
	{
		i = -1;
		while (envp[++i])
		{
			if (!(ft_strncmp(envp[i], "PATH=", 5)))
				break ;
		}
		pipex.path = ft_strdup(envp[i] + 5);
		pipex.path_ptr = ft_split(pipex.path, ':');
		if (!(envp[i]))
			exit_wout_free("Problem on finding PATH in envp", 1);
	}
	pipex.command_ptr = ft_split(argv, ' ');
	pipex.command = ft_strdup(pipex.command_ptr[0]);
	pipex_join(pipex);
	ft_execute_2(pipex, envp, j);
}


void	ft_execute_2(t_pipex pipex, char **envp, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		find_executable(&pipex, &i);
		if (execve(pipex.path_ptr[i], pipex.command_ptr, envp) == -1)
		exit_w_free("exec problem", pipex, 127);
	}
	else
	{
		if (access(pipex.path, X_OK) == 0)
		{
			if (execve(pipex.path, pipex.command_ptr, envp) == -1)
				exit_w_free("exec problem", pipex, 127); // buraya pathptr temizlenmesine gerek yok
		}
		exit_w_free("exec problem", pipex, 127); // buraya pathptr temizlenmesine gerek yok

	}
}

void	find_executable(t_pipex *pipex, int *i)
{
	while (pipex->path_ptr[*i])
	{
		if (access(pipex->path_ptr[*i], X_OK) == 0)
			return ;
		(*i)++;
	}
	exit_w_free("exec problem", *pipex, 127);
}

void	pipex_join(t_pipex pipex)
{
	int		i;
	char	*temp;

	i = 0;
	while (pipex.path_ptr[i])
	{
		temp = pipex.path_ptr[i];
		pipex.path_ptr[i] = ft_strjoin(temp, "/");
		free(temp);
		temp = pipex.path_ptr[i];
		pipex.path_ptr[i] = ft_strjoin(temp, pipex.command);
		free(temp);
		i++;
	}
}
