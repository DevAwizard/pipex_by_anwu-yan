/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:43:17 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:13:31 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_error_and_exit(t_pipex *pipex, const char *message, int error_code)
{
	if (message)
	{
		write(STDERR_FILENO, message, ft_strlen(message));
		write(STDERR_FILENO, "\n", 1);
	}
	if (pipex)
	{
		if (pipex->cmd_path1)
			free(pipex->cmd_path1);
		if (pipex->cmd_path2)
			free(pipex->cmd_path2);
		if (pipex->argv_cmd1)
			free_split_parse_cmd(pipex->argv_cmd1);
		if (pipex->argv_cmd2)
			free_split_parse_cmd(pipex->argv_cmd2);
		if (pipex->paths)
			free_env_paths(pipex);
		if (pipex->input_fd != -1)
			close(pipex->input_fd);
		if (pipex->output_fd != -1)
			close(pipex->output_fd);
	}
	exit (error_code);
}
