/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 23:34:13 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/23 23:34:13 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int     pipefd[2];
    pid_t   pid1;
    pid_t   pid2;
    int     status;

    if (argc != 5)
        exit_error("Usage: ./pipex infile cmd1 cmd2 outfile");
    if (pipe(pipefd) == -1)     // pipefd[0] = read end | pipefd[1] = write end
        exit_error("pipe failed");
    pid1 = exec_child1(argv, envp, pipefd);      // Run first child (infile -> cmd1 -> pipe write)
    pid2 = exec_child2(argv, envp, pipefd);      // run second child (pipe read -> cmd2 -> outfile)
    close(pipefd[0]);     // parent process close both ends as it doesnt need to read or write from pipe only children need
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status)) // Return exit code of cmd2
        return (WEXITSTATUS(status));
    return (1);
}