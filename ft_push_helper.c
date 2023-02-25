/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:19:59 by mrami             #+#    #+#             */
/*   Updated: 2023/02/25 18:50:01 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*str1;
	char		*str2;
	size_t		i;

	str1 = src;
	str2 = dst;
	i = 0;
	if (str1 == str2)
		return (dst);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_isdegit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	if ((str[i] == '-' && str[i + 1] == '-')
		|| (str[i] == '+' && str[i + 1] == '+'))
		ft_print_error("Error: plus than one (-) or (+) Found!");
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + str[i] - '0';
		i++;
	}
	if (ft_check_max_min(num) && (sign == 1 || sign == -1))
		ft_print_error("Error: Big number Found!");
	return (sign * num);
}
