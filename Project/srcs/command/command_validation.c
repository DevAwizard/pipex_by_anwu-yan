/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:10:22 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:39:03 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Helper function to construct command path and check access
static char	*construct_command_path(char *cmd, char *path_prefix)
{
	char	*temp_path;
	char	*cmd_path;

	temp_path = ft_strjoin(path_prefix, "/");
	if (!temp_path)
		return (NULL);
	cmd_path = ft_strjoin(temp_path, cmd);
	free(temp_path);
	if (!cmd_path)
		return (NULL);
	if (access(cmd_path, X_OK) == 0)
		return (cmd_path);
	free (cmd_path);
	return (NULL);
}

// Helper function to clean up and set command path
static void	set_command_path(t_pipex *pipex, char *cmd_path, int cmd_num)
{
	if (cmd_num == 1)
	{
		if (pipex->cmd_path1)
			free(pipex->cmd_path1);
		pipex->cmd_path1 = cmd_path;
	}
	else if (cmd_num == 2)
	{
		if (pipex->cmd_path2)
			free(pipex->cmd_path2);
		pipex->cmd_path2 = cmd_path;
	}
}

// Main function for command validation
void	validate_command(t_pipex *pipex, char *cmd, int cmd_num)
{
	char	*cmd_path;
	int		i;

	i = 0;
	if (!cmd || cmd[0] == '\0')
		ft_error_and_exit (pipex, "Error: Command not found", EXIT_FAILURE);
	if (!pipex->paths)
		ft_error_and_exit (pipex, "Error: PATH variable", EXIT_FAILURE);
	while (pipex->paths[i])
	{
		cmd_path = construct_command_path(cmd, pipex->paths[i]);
		if (cmd_path)
		{
			set_command_path(pipex, cmd_path, cmd_num);
			return ;
		}
		i++;
	}
	ft_error_and_exit (pipex, "Error: Command not found", EXIT_FAILURE);
}
