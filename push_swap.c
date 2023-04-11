/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:15:49 by mrami             #+#    #+#             */
/*   Updated: 2023/04/11 01:13:10 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	int		i;
	t_stack	stack_b;

	stack_b.stack = 0;
	stack_a.stack = 0;
	i = 0;
	ft_split_to_atio(argc, argv, &stack_a);
	if (!ft_check_sorting(&stack_a))
		return (0);
	else
		ft_big_number(&stack_a, &stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
