/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:29 by mrami             #+#    #+#             */
/*   Updated: 2023/02/15 15:14:47 by mrami            ###   ########.fr       */
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

char	*ft_get_all_args(int argc, char const *argv[])
{
	int		total_len;
	int		i;
	char	*total_args;
	int		j;
	size_t	arg_len;

	total_len = ft_lenght_args(argc, argv);
	total_args = malloc(total_len + 1);
	if (total_args == NULL)
		return (NULL);
	j = 0;
	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		ft_memcpy(total_args + j, argv[i], arg_len);
		j += arg_len;
		total_args[j++] = ' ';
		i++;
	}
	total_args[total_len] = '\0';
	return (total_args);
}

int	*ft_split_to_atio(int argc, char const *argv[])
{
	char	*arg;
	char	**spliter;
	int		i;
	int		num_ints;
	int		*results;

	arg = ft_get_all_args(argc, argv);
	spliter = ft_split(arg, ' ');
	num_ints = 0;
	i = 0;
	while (spliter[i] != NULL)
	{
		num_ints++;
		i++;
	}
	results = (int *)malloc(sizeof(int) * num_ints);
	i = 0;
	while (spliter[i] != NULL)
	{
		results[i] = ft_atoi(spliter[i]);
		free(spliter[i]);
		i++;
	}
	free(spliter);
	return (results);
}

int	main(int argc, char const *argv[])
{
	int *res;
	int i;
	i = 0;
	res = ft_split_to_atio(argc, argv);
	while (i < argc - 1)
	{
		printf("%d\n", *res);
		i++;
	}
	free(res);
	return (0);
}

