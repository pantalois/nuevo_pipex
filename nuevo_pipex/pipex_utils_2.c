/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:56 by loigonza          #+#    #+#             */
/*   Updated: 2024/06/18 19:01:56 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex2.h"


char	**ft_getenv(char *env[])
{
	int j;
	char *env_path;
	char **split_res;
	int i;
	
	j = 0;
	while (env[j] != NULL)
	{
		if((ft_strncmp(env[j], "PATH=", 5)) == 0)
			env_path = env[j];
		j++;
	}
	split_res = ft_split(&env_path[5], ':');
	i = 0;
	while (split_res[i])
	{
		split_res[i] = ft_strjoin(split_res[i], "/");
		i++;
	}
	return (split_res);
}

int	ft_fork(char *env[], char *argv[], char *split_res[])
{
	pid_t pid;
	//char **cmd[2];
	//int i;
	char *path;
	char **cmd;
	
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		path = ft_slash(/*env, */argv, split_res);
		cmd = create_command(argv[0]);
		printf("tengo el cmd\n");
		pipe_dup2(path, cmd, env);
		write(2, "sale\n", 5);
		//execve(e
		return (0);
	}
	if (pid > 0)
	{
		wait(NULL);
		wait(NULL);
		return (0);
	}
	return (0);
}

char	*ft_slash(/*char *env[], */char *argv[], char *split_res[])
{
	int	j;
	char *tmp;//esto es el comando

	j = 0;
	tmp = argv[j];

	if (tmp[j] == '/')//si nos pasan esto salimos de la funcion para
						  //mirar el access y preparar el commando
						  ////preparar el comando para el execve
		return (tmp);
	else
	{
		while (split_res[j])
		{
			split_res[j] = ft_strjoin(split_res[j], tmp);
			if (access(split_res[j], X_OK) == 0)
				return (split_res[j]);
			else
			{
				free(split_res[j]);
				j++;
			}	
		}
	}
	return (tmp);
}

int	open_file(char *outfile, char *infile)
{
	int fd_i;
	int fd_o;


}
