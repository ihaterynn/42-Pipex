/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 04:39:57 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/25 04:39:57 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_path(char *envp[])
{
    char **dirs;
    int i;

    i = 0;
    while (envp[i] != NULL)
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
            break;
        i++;
    }
    if (!envp[i])
        return (NULL);
    dirs = ft_split(envp[i] + 5, ':');
    return (dirs);
}

static char *find_executable_path(char **path, char *cmd)
{
    int i;
    char *temp;
    char *exec_path;

    i = 0;
    while (path && path[i])
    {
        temp = ft_strjoin(path[i], "/");
        exec_path = ft_strjoin(temp, cmd);
        free(temp);
        if (access(exec_path, X_OK) == 0)
            return (exec_path);
        free(exec_path);
        i++;
    }
    return (NULL);
}

void    parse_command(t_pipex *cmd, char **path, char *arg_str)
{
    cmd->exec_path = NULL;
    cmd->args = NULL;
    if (!arg_str || arg_str[0] == '\0')
        return;
    cmd->args = ft_split(arg_str, ' ');
    if (!cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
        return ;
    if (access(cmd->args[0], X_OK) == 0)
    {
        cmd->exec_path = ft_strdup(cmd->args[0]);
        return ;
    }
    cmd->exec_path = find_executable_path(path, cmd->args[0]);
}