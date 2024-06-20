/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:51:26 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/18 16:49:08 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX2_H
# define PIPEX2_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

char **ft_getenv(char *env[]);
int	ft_fork(char *env[], char *argv[], char *split_res[]);
char *ft_slash(/*char *env[], */char *argv[], char *split_res[]);
char **create_command(char *argv);
void pipe_dup2();

#endif
