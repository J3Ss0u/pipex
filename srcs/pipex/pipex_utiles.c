/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:08:35 by sacharai          #+#    #+#             */
/*   Updated: 2023/05/25 23:23:01 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_dupfd1(char *file1)
{
	int	fd1;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
	{
		perror("fd");
		exit(1);
	}
	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(fd1);
}

void	ft_dupfd2(char *file2)
{
	int	fd2;

	fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
}

char	*check_env_path(char **argenv)
{
	char	*env;

	env = "PATH";
	while (*argenv && ft_strncmp(*argenv, env, 4) != 0)
		(argenv)++;
	if (!*argenv)
	{
		write(2, "> The environment variable PATH not exist\n", 42);
		exit(1);
	}
	return (*argenv + 5);
}

void	close_cmd1(int fd[2])
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	close_cmd2(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
