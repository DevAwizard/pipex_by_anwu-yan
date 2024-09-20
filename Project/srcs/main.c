/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:13:27 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:35:02 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	initialize_pipex(t_pipex *pipex)
{
	pipex->input_fd = -1;
	pipex->output_fd = -1;
	pipex->argv_cmd1 = NULL;
	pipex->argv_cmd2 = NULL;
	pipex->paths = NULL;
	pipex->cmd_path1 = NULL;
	pipex->cmd_path2 = NULL;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		pipe_fd[2];

	initialize_pipex(&pipex);
	if (argc != 5)
		ft_error_and_exit (&pipex, "Error invalid arguments", EXIT_FAILURE);
	setup_paths(&pipex, envp);
	analyze_file_arguments(&pipex, argv);
	parse_commands(&pipex, argv);
	create_pipe(&pipex, pipe_fd);
	execute_first_command(&pipex, envp, pipe_fd);
	execute_second_command(&pipex, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	close(pipex.input_fd);
	close(pipex.output_fd);
	free_command_paths(pipex.cmd_path1, pipex.cmd_path2);
	cleanup_commands(&pipex);
	return (0);
}
