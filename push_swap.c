/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:15:49 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 21:16:28 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	int		i;
	t_stack	stack_b;

	stack_b.stack = 0;
	i = 0;
	ft_split_to_atio(argc, argv, &stack_a);
	if (!ft_check_sorting(&stack_a))
	{
		while (i < stack_a.counter)
			printf("sa->%d\n", stack_a.stack[i++]);
	}
	else
	{
		ft_big_number(&stack_a, &stack_b);
		while (i < stack_a.counter)
			printf("sa->%d\n", stack_a.stack[i++]);
	}
	return (0);
}
