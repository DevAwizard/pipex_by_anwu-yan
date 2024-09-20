/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:39:53 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:36:13 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	analyze_file_arguments(t_pipex *pipex, char **argv)
{
	int	flags;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->input_fd = open(pipex->infile, O_RDONLY);
	if (pipex->input_fd == -1)
		ft_error_and_exit(pipex, "Error opening input file", EXIT_FAILURE);
	pipex->output_fd = open(pipex->outfile, flags, 0644);
	if (pipex->output_fd == -1)
		ft_error_and_exit(pipex, "Error opening output file", EXIT_FAILURE);
}

void	parse_commands(t_pipex *pipex, char **argv)
{
	pipex->argv_cmd1 = ft_split(argv[2], ' ');
	if (!pipex->argv_cmd1)
		ft_error_and_exit (pipex, "Error parsing command 1", EXIT_FAILURE);
	validate_command(pipex, pipex->argv_cmd1[0], 1);
	pipex->argv_cmd2 = ft_split(argv[3], ' ');
	if (!pipex->argv_cmd2)
	{
		free_split_parse_cmd(pipex->argv_cmd1);
		ft_error_and_exit(pipex, "Error parsing command 2", EXIT_FAILURE);
	}
	validate_command (pipex, pipex->argv_cmd2[0], 2);
}

void	setup_paths(t_pipex *pipex, char **envp)
{
	char	*path_var;
	int		i;

	path_var = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_var = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_var || path_var[0] == '\0')
		ft_error_and_exit (pipex, "Error: PATH not found", EXIT_FAILURE);
	pipex->paths = ft_split(path_var, ':');
	if (!pipex->paths)
	{
		free_env_paths(pipex);
		ft_error_and_exit (pipex, "Error: Failed to parse PATH", EXIT_FAILURE);
	}
}

void	create_pipe(t_pipex *pipex, int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		ft_error_and_exit (pipex, "Error creating pipe", EXIT_FAILURE);
}
