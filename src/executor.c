/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 06:49:54 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/26 06:49:54 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec_command(char *exec_path, char **args, char *envp[])
{
    execve(exec_path, args, envp);
    print_error("execve failed");
    exit(1);
}

static void setup_child1_io(char *infile, int *pipefd)
{
    int fd;

    fd = open_infile(infile);
    if (fd == -1)
        exit(1);
    dup2(fd, STDIN_FILENO);
    close(fd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
}

static void setup_child2_io(char *outfile, int *pipefd)
{
    int fd;

    fd = open_outfile(outfile);
    if (fd == -1)
        exit(1);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
}

static void execute_cmd(t_pipex *cmd, char **path, char *envp[])
{
    free_path(path);
    if (!cmd->exec_path)
    {
        free_cmd(cmd);
        print_error("command not found");
        exit(127);
    }
    execve(cmd->exec_path, cmd->args, envp);
    print_error("execve failed");
    free_cmd(cmd);
    exit(1);
}

pid_t   exec_child1(char *argv[], char *envp[], int *pipefd)
{
    pid_t pid;
    char **path;
    t_pipex cmd;

    pid = fork();
    if (pid == -1)
        exit_error("fork failed");
    if (pid == 0)
    {
        setup_child1_io(argv[1], pipefd);
        path = get_path(envp);
        parse_command(&cmd, path, argv[2]);
        execute_cmd(&cmd, path, envp);
    }
    return (pid);
}

pid_t   exec_child2(char *argv[], char *envp[], int *pipefd)
{
    pid_t pid;
    char **path;
    t_pipex cmd;

    pid = fork();
    if (pid == -1)
        exit_error("fork failed");
    if (pid == 0)
    {
        setup_child2_io(argv[4], pipefd);
        path = get_path(envp);
        parse_command(&cmd, path, argv[3]);
        execute_cmd(&cmd, path, envp);
    }
    return (pid);
}