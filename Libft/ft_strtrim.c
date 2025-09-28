/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:41:03 by ryachan           #+#    #+#             */
/*   Updated: 2025/05/30 09:41:03 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_find_start(const char *s1, const char *set)
{
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	return (s1);
}

const char	*ft_find_end(const char *s1, const char *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	return (s1 + len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t		len;
	const char	*start;
	const char	*end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	len = end - start;
	return (ft_substr(s1, (start - s1), len));
}
/*
#include <stdio.h>
int main(void)
{
    char *result;

    // Case 1: Trimming whitespace
    result = ft_strtrim("   Hello, World!   ", " ");
    printf("Trimmed: '%s'\n", result);
    free(result);

    // Case 2: Trimming specific chars from both ends
    result = ft_strtrim("xxhixxx42KL Rocksxxx dkdkc xxxx", "x");
    printf("Trimmed: '%s'\n", result);
    free(result);

    // Case 3: Set includes multiple characters
    result = ft_strtrim("ababaaaMy name is Simonbbaaabbad", "ab");
    printf("Trimmed: '%s'\n", result);
    free(result);

    // Case 4: No trimming needed
    result = ft_strtrim("OpenAI", "xyz");
    printf("Trimmed: '%s'\n", result);
    free(result);

    // Case 5: All chars in set (return empty string)
    result = ft_strtrim("aaaa", "a");
    printf("Trimmed: '%s'\n", result);
    free(result);

    return 0;
}*/
