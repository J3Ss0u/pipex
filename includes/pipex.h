/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <sacharai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:11:52 by sacharai          #+#    #+#             */
/*   Updated: 2023/05/25 23:25:04 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "../srcs/ft_printf/ft_printf.h"
# include "../srcs/libft/libft.h"

char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*find_path(char *full_paths, char *cmd);
void	ft_dupfd1(char *file1);
void	ft_dupfd2(char *file2);
char	*check_env_path(char **argenv);
void	close_cmd1(int fd[2]);
void	close_cmd2(int fd[2]);
void	end_close(int fd1, int fd2, int p1, int p2);
void	err_cmd(char *cmd);

#endif