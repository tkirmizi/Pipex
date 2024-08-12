/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:09:57 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/08/11 14:26:29 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_pipex
{
	int		fds[2];
	pid_t	pid;
	char	**path_ptr;
	char	**command_ptr;
	char	*path;
	char	*command;
}			t_pipex;

void	arg_check_frw(char **argv);
void	child_process(t_pipex pipex, char **argv, char **envp);
void	parent_process(t_pipex pipex, char **argv, char **envp);
void	ft_execute(t_pipex pipex, char *argv, char **envp);
void	find_executable(t_pipex *pipex, int *i);
void	ft_execute_2(t_pipex pipex, char **envp, int j);
void	exit_w_free(const char *message, t_pipex pipex, int i);
void	exit_wout_free(const char *message, int j);
void	pipex_join(t_pipex pipex);

#endif