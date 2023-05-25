/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:00:52 by sacharai          #+#    #+#             */
/*   Updated: 2023/05/25 22:57:43 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	fork_and_get_id(void)
{
	int	id;

	id = fork();
	if (id == -1)
		perror("fork");
	return (id);
}

char	*parce(int ac, char **argenv)
{
	char	*full_path;

	if (ac != 5)
	{
		ft_printf("Usage: [FILE1]... [CMD1]... [CMD2]... [FILE2]...\n");
		exit(1);
	}
	full_path = check_env_path(argenv);
	return (full_path);
}

void	ft_process1(char *full_path, char *full_cmd, char *file1, int fd[2])
{
	char	**cmd;
	char	*path;

	ft_dupfd1(file1);
	cmd = ft_split(full_cmd, ' ');
	if (!cmd[0])
	{
		write(2, "Enter the correct command\n", 26);
		exit(1);
	}
	path = find_path(full_path, cmd[0]);
	if (!path)
		exit(1);
	close_cmd1(fd);
	execve(path, cmd, NULL);
	perror("execve");
}

void	ft_process2(char *full_path, char *full_cmd, char *file2, int fd[2])
{
	char	**cmd;
	char	*path;

	ft_dupfd2(file2);
	cmd = ft_split(full_cmd, ' ');
	if (!cmd[0])
	{
		write(2, "Enter the correct command\n", 26);
		exit(1);
	}
	path = find_path(full_path, cmd[0]);
	if (!path)
		exit(1);
	close_cmd2(fd);
	execve(path, cmd, NULL);
	perror("execve");
}

int	main(int ac, char **av, char **argenv)
{
	char	*full_path;
	int		pid1;
	int		fd[2];
	int		pid2;

	full_path = parce(ac, argenv);
	if (pipe(fd) == -1)
		return (perror("pipe"), 0);
	pid1 = fork_and_get_id();
	if (pid1 == 0)
	{
		ft_process1(full_path, av[2], av[1], fd);
		return (1);
	}
	pid2 = fork_and_get_id();
	if (pid2 == 0)
	{
		ft_process2(full_path, av[3], av[4], fd);
		return (2);
	}
	end_close(fd[0], fd[1], pid1, pid2);
	return (0);
}
