/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 05:51:55 by ryachan           #+#    #+#             */
/*   Updated: 2025/06/02 05:51:55 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	extract_words(const char *s, char c, char **res, size_t word_count)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i] && k < word_count)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
			res[k++] = ft_substr(s, i, j);
		i += j;
	}
	res[k] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	res = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!res)
		return (NULL);
	extract_words(s, c, res, word_count);
	return (res);
}
/*
#include <stdio.h>
void print_split(char **result)
{
	int i = 0;
	while (result[i])
	{
		printf("res[%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	printf("res[%d]: NULL\n\n", i);
}

void free_split(char **res)
{
	int i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

// -------- Main Test Function --------
int main(void)
{
	char **res;

	// Test 1
	res = ft_split("hello-world-split", '-');
	printf("Test 1:\n");
	print_split(res);
	free_split(res);

	// Test 2
	res = ft_split("--hello--world--split--", '-');
	printf("Test 2:\n");
	print_split(res);
	free_split(res);

	// Test 3
	res = ft_split("nowordbreaks", '-');
	printf("Test 3:\n");
	print_split(res);
	free_split(res);

	// Test 4
	res = ft_split("------", '-');
	printf("Test 4:\n");
	print_split(res);
	free_split(res);

	// Test 5
	res = ft_split("", '-');
	printf("Test 5:\n");
	print_split(res);
	free_split(res);

	return (0);
}
*/
