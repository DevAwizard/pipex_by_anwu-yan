/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:39:53 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/19 17:14:23 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_first_command(t_pipex *pipex, char **envp, int pipe_fd[2])
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_error_and_exit(pipex, "Fork failed", EXIT_FAILURE);
	if (pipex->pid1 == 0)
	{
		if (dup2(pipex->input_fd, STDIN_FILENO) == -1)
			ft_error_and_exit(pipex, "dup2 failed for input redirection", EXIT_FAILURE);
		close(pipex->input_fd);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error_and_exit(pipex, "dup2 failed for output redirection", EXIT_FAILURE);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(pipex->cmd_path1, pipex->argv_cmd1, envp);
		ft_error_and_exit(pipex, "Error executing 1st command", EXIT_FAILURE);
	}
}

void	execute_second_command(t_pipex *pipex, char **envp, int pipe_fd[2])
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		ft_error_and_exit(pipex, "Fork failed", EXIT_FAILURE);
	if (pipex->pid2 == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			ft_error_and_exit(pipex, "dup2 failed for input redirection", EXIT_FAILURE);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		if (dup2(pipex->output_fd, STDOUT_FILENO) == -1)
			ft_error_and_exit(pipex, "dup2 failed for output redirection", EXIT_FAILURE);
		close(pipex->output_fd);
		execve(pipex->cmd_path2, pipex->argv_cmd2, envp);
		ft_error_and_exit(pipex, "Error executing 2nd command", EXIT_FAILURE);
	}
}

