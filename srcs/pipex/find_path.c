/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:23:19 by sacharai          #+#    #+#             */
/*   Updated: 2023/05/25 23:20:31 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '/';
	i++;
	dest[i] = '\0';
	return (dest);
}

char	*search(char **path, char *cmd, int *fd, int *c)
{
	char	*joined;
	char	*filepath;

	filepath = malloc(ft_strlen(path[*c]) + ft_strlen(cmd) + 2);
	if (filepath == NULL)
		return (perror(""), free(path), NULL);
	ft_strcpy(filepath, path[*c]);
	joined = ft_strjoin(filepath, cmd);
	*fd = open(joined, O_RDONLY);
	if (*fd == -1)
	{
		free(joined);
		return (NULL);
	}
	return (joined);
}

char	*find_path(char *full_paths, char *cmd)
{
	char	**path;
	int		i;
	int		c;
	int		fd;
	char	*joined;

	i = 0;
	c = 0;
	fd = -1;
	if (cmd[i] == '/' || cmd[i] == '.')
		return (cmd);
	path = ft_split(full_paths, ':');
	if (path)
	{
		while (path[i])
			i++;
		while (c++ < i - 1 && fd == -1)
			joined = search(path, cmd, &fd, &c);
		if (fd == -1)
			err_cmd(cmd);
		return (free(path), joined);
	}
	return (NULL);
}

void	end_close(int fd1, int fd2, int p1, int p2)
{
	close(fd1);
	close(fd2);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
}
