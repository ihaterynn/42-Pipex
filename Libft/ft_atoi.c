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

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}


int	ft_parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (str[*i] == '+' || str[*i] == '-')
		return (0);
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_parse_sign(str, &i);
	if (sign == 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*int main()
{
    int result;

    result = ft_atoi("123abc456");
    printf("Input: \"123abc456\" -> Output: %d\n", result); // output: 123

    result = ft_atoi("abc123");
    printf("Input: \"abc123\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("--+++1234abc56");
    printf("Input: \"--+++1234abc56\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("");
    printf("Input: \"\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("   -0012a42");
    printf("Input: \"   -0012a42\" -> Output: %d\n", result); // output: -12

    result = ft_atoi("0");
    printf("Input: \"0\" -> Output: %d\n", result); // output: 0

    return 0;
}*/
