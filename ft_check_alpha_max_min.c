/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_alpha_max_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:21:03 by mrami             #+#    #+#             */
/*   Updated: 2023/02/18 15:34:04 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_utils.h"

// check if thieres an alphabitic

int	ft_check_alpha(int args, char const *argv[])
{
	char	*str;
	int		i;

	str = ft_get_all_args(args, argv);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_max_min(long num)
{
	if (num <= INT_MIN || num >= INT_MAX)
		return (1);
	return (0);
}
