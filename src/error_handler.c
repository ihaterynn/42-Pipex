/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:16:03 by ryachan           #+#    #+#             */
/*   Updated: 2025/08/27 17:16:03 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print_error(const char *msg)
{
    perror(msg);
}

void    exit_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}