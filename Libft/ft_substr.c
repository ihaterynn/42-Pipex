/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:44 by ryachan           #+#    #+#             */
/*   Updated: 2025/05/31 16:30:44 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc((len + 1), sizeof(char));
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char *s = "Hello, world!";
    char *sub;

    sub = ft_substr(s, 0, 5);   // "Hello"
    printf("1: %s\n", sub);
    free(sub);

    sub = ft_substr(s, 7, 5);   // "world"
    printf("2: %s\n", sub);
    free(sub);

    sub = ft_substr(s, 20, 5);  // "" (start > strlen)
    printf("3: '%s'\n", sub);
    free(sub);

    sub = ft_substr(s, 4, 20);  // "o, world!"
    printf("4: %s\n", sub);
    free(sub);

    return 0;
}*/
