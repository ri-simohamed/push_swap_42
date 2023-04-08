/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:41:56 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 21:26:46 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* check Actions */

void	ft_check_action(t_stack *stack1)
{
	
}

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	stack_b.stack = 0;
	ft_split_to_atio(argc, argv, &stack_a);
	i = 0;
	while (i < stack_a.counter)
		printf("--->%d\n", stack_a.stack[i++]);

	return (0);
}

