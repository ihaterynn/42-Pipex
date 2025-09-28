/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:44:24 by ryachan           #+#    #+#             */
/*   Updated: 2025/05/30 03:44:24 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while ((needle[j] != '\0' && haystack[i + j] == needle[j])
			&& i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void) {
    const char *h1 = "Foo Bar Baz";
    const char *n1 = "Bar";

    // Test 1: Basic find
    ft_strnstr(h1, n1, 11); // len covers the whole string

    // Test 2: Needle not found
    ft_strnstr(h1, "Quux", 11);

    // Test 3: Needle present, but len is too short
    ft_strnstr(h1, n1, 5); // false.

    // Test 4: Needle present, len is just enough
    ft_strnstr(h1, n1, 7); // "Foo Bar" - Bar starts at index 4. 4+2 = 6. 6 < 7.

    // Test 5: Empty needle
    ft_strnstr(h1, "", 11);
    ft_strnstr(h1, "", 0); // Empty needle, len 0

    // Test 6: Needle at the beginning
    ft_strnstr(h1, "Foo", 11);
    ft_strnstr(h1, "Foo", 2); // len too short for "Foo"

    return 0;
}*/
