/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:19:08 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/24 01:19:08 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

// STRUCTS

typedef struct s_pipex
{
    char    *exec_path;
    char    **args;
}   t_pipex;

// PARSER

char    **get_path(char *envp[]);
void    parse_command(t_pipex *cmd, char **path, char *arg_str);

// EXECUTOR

void    exec_command(char *exec_path, char **args, char *envp[]);
pid_t   exec_child1(char *argv[], char *envp[], int *pipefd);
pid_t   exec_child2(char *argv[], char *envp[], int *pipefd);

// UTILS

int     open_infile(char *infile);
int     open_outfile(char *outfile);
void    free_cmd(t_pipex *cmd);
void    free_path(char **path);

// ERROR HANDLER

void    print_error(const char *msg);
void    exit_error(const char *msg);

# endif