/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:01:36 by ryachan           #+#    #+#             */
/*   Updated: 2025/05/29 18:01:36 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*ptr;
	int		i;

	cc = (char) c;
	i = 0;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			ptr = ((char *)&s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (ptr);
}
