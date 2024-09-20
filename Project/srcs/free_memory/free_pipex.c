/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:09:48 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:17:03 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	free_split_parse_cmd(char **split)
{
	int		i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Function to free the memory allocated by ft_split for PATH directories
void	free_env_paths(t_pipex *pipex)
{
	if (pipex->paths)
	{
		free_split_parse_cmd(pipex->paths);
		pipex->paths = NULL;
	}
}

static	void	close_file_descriptors(t_pipex *pipex)
{
	if (pipex->input_fd != -1)
		close(pipex->input_fd);
	if (pipex->output_fd != -1)
		close(pipex->output_fd);
}

void	cleanup_commands(t_pipex *pipex)
{
	if (pipex->argv_cmd1)
		free_split_parse_cmd(pipex->argv_cmd1);
	if (pipex->argv_cmd2)
		free_split_parse_cmd(pipex->argv_cmd2);
	if (pipex->paths)
		free_env_paths(pipex);
	close_file_descriptors(pipex);
}

// Function to free command paths (cmd_path1 and cmd_path2)
void	free_command_paths(char *cmd_path1, char *cmd_path2)
{
	if (cmd_path1)
		free(cmd_path1);
	if (cmd_path2)
		free(cmd_path2);
}
