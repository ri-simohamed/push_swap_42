/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alpha_max_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:21:03 by mrami             #+#    #+#             */
/*   Updated: 2023/02/25 15:37:46 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

// check if thieres an alphabitic

int	ft_check_alpha(int args, char const *argv[])
{
	char	*str;
	int		i;

	str = ft_get_all_args(args, argv);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdegit(str[i]) && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

// check the max and min

int	ft_check_max_min(long num)
{
	if (num <= INT_MIN || num >= INT_MAX)
		return (1);
	return (0);
}

// print Error

void	ft_print_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit (1);
}

// check duplication

int	ft_check_dup(int *arr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (arr[i])
		i++;
	len = i;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
