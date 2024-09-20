/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:13:31 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/09/12 07:35:32 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h> 
# include <stdbool.h>
# include "../srcs/libft/libft.h"

typedef struct s_pipex
{
	int		input_fd;
	int		output_fd;
	int		fd_pipe[2];
	char	**paths;
	char	**argv_cmd1;
	char	**argv_cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	char	*infile;
	char	*outfile;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

// ========== Initialization and Argument Parsing ==========
// Initialize the pipex structure and parse command-line arguments
void	initialize_pipex(t_pipex *pipex);
void	analyze_file_arguments(t_pipex *pipex, char **argv);
void	parse_commands(t_pipex *pipex, char **argv);
void	validate_command(t_pipex *pipex, char *cmd, int cmd_num);

// ========== Fork and Command Execution ==========
// Functions to execute commands and handle process forking
void	execute_first_command(t_pipex *pipex, char **envp, int pipe_fd[2]);
void	execute_second_command(t_pipex *pipex, char **envp, int pipe_fd[2]);

// ========== Path Management ==========
// Functions to handle PATH variable parsing and command validation
void	setup_paths(t_pipex *pipex, char **envp);

// ========== Create Pipe =============
void	create_pipe(t_pipex *pipex, int pipe_fd[2]);

// ========== Error Handling ==========
// Handle errors and exit the program safely
void	ft_error_and_exit(t_pipex *pipex, const char *message, int error_code);

// ========== Memory Management ==========
// Functions to free allocated memory and cleanup resources
void	free_split_parse_cmd(char **split);
void	cleanup_commands(t_pipex *pipex);
void	free_command_paths(char *cmd_path1, char *cmd_path2);
void	free_env_paths(t_pipex *pipex);

#endif