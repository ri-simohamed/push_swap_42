/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:29 by mrami             #+#    #+#             */
/*   Updated: 2023/02/14 21:11:38 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_utils.h"

int	ft_lenght_args(int argc, char const *argv[])
{
	int	i;
	int	total_len;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]);
		i++;
	}
	total_len += argc - 2;
	return (total_len);
}


char	*ft_concat_args(int argc, char const *argv[])
{
	char	*concat;
	int		i;
	int		args_lenght;

	args_lenght = ft_lenght_args(argc, argv);
	printf("len ----> %d\n", args_lenght);
	i = 1;
	concat = malloc(args_lenght + 1);
	if (!concat)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		ft_strcat(concat, argv[i]);
		if (i < argc - 1)
		{
			ft_strcat(concat, " ");
		}
		i++;
	}
	return (concat);
}

int	main(int argc, char const *argv[])
{
	char	*str;

	str = ft_concat_args(argc, argv);
	printf("%s", str);
	return (0);
}
