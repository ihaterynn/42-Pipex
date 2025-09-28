/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 05:04:38 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/25 05:04:38 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     open_infile(char *infile)
{
    int fd;

    fd = open(infile, O_RDONLY);
    if (fd == -1)
    {
        perror(infile);
        return (-1);
    }
    return (fd);
}

int     open_outfile(char *outfile)
{
    int fd;

    fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror(outfile);
        return (-1);
    }
    return (fd);
}

void    free_path(char **path)
{
    int i;

    i = 0;
    if (!path)
        return;
    while (path[i] != NULL)
    {
        free(path[i]);
        i++;
    }
    free(path);
}

void free_cmd(t_pipex *cmd)
{
    int i;

    if (!cmd)
        return;
    if (cmd->exec_path)
        free(cmd->exec_path);
    if (cmd->args)
    {
        i = 0;
        while (cmd->args[i])
        {
            free(cmd->args[i]);
            i++;
        }
        free(cmd->args);
    }
}