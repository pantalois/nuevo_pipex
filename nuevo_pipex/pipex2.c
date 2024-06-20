/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:49:26 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/18 19:01:46 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex2.h"

int	main(int argc, char *argv[], char *env[])
{
	char **split_res;
	int i;
	int fd;

	i = 2;//obvio el infile en este caso.
	if (argc != 5)
		return (0);
	fd = open_file(argv[argc - 1], argv[1]);
		return (0);
		//print error
		//
	while (argv[i + 1])
	{
	split_res = ft_getenv(env);
	//crear subprocesos.
	ft_fork(env, &argv[i], split_res);
	i++;
	}
	//saliendo del bucle estamos en el outfile
	return (0);
}


char **create_command(char *argv)
{
	//int i = 0;
	char **cmd;
	//size_t len;


	cmd = ft_split(argv, ' ');
	//len = ft_strlen(*cmd);
	//printf("LEN DE CMD %zu\n", len);
	//len = ft_strlen(cmd[1]);
	/*while (cmd != NULL)
	{

		printf("POSICIONES CMD %s\n", cmd[i]);
		i++;
	}*/
	return (cmd);
}

void	pipe_dup2(char *path, char **cmd, char **env)
{
	int fd[2];

	if (pipe(fd) == -1)
		return ;
	printf("%d\n", fd[0]);
	printf("%d\n", fd[1]);
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{	
		write(2,"fallo\n", 6);
		return ;//mensaje error
	}
	write(2, "12345", 5);
	write(2, "\n", 1);
	execve(path, cmd, env);
}
