/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryachan <ryachan@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:30:32 by ryachan           #+#    #+#             */
/*   Updated: 2025/05/31 15:30:32 by ryachan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int main(void)
{
    const char *original = "Hello, 42!";
    char *copy;

    copy = ft_strdup(original);
    if (copy)
    {
        printf("Duplicated string: \"%s\"\n", copy);
        free(copy);
    }
    else
        printf("Memory allocation failed.\n");
    return 0;
}*/
