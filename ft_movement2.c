/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:18:49 by mrami             #+#    #+#             */
/*   Updated: 2023/03/25 17:33:42 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* push top of an stack to the top of another stack */

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	int	*stack_b_tap;
	int	*stack_a_tap;
	int	count;

	if (stack_a->counter == 0)
		return ;
	count = stack_b->counter + 1;
	stack_b_tap = malloc((count) * sizeof(int));
	if (!stack_b_tap)
		return ;
	if (stack_b->counter > 0)
		ft_memcpy(stack_b_tap + 1, stack_b->stack,
			(count) * sizeof(int));
	stack_b_tap[0] = stack_a->stack[0];
	stack_b->counter++;
	stack_b->stack = stack_b_tap;
	count = stack_a->counter - 1;
	stack_a_tap = malloc((count) * sizeof(int));
	if (!stack_a_tap)
		return ;
	ft_memcpy(stack_a_tap, stack_a->stack + 1,
		(count) * sizeof(int));
	stack_a->counter--;
	stack_a->stack = stack_a_tap;
}

/* max number of an array */

int	ft_get_max_of_stack(t_stack *stack1)
{
	int	len;
	int	i;
	int	max_s;

	len = stack1->counter;
	max_s = stack1->stack[0];
	i = 0;
	while (i < len)
	{
		if (stack1->stack[i] > max_s)
			max_s = stack1->stack[i];
		i++;
	}
	return (max_s);
}

/* min number of an array */

int	ft__get_min_of_stack(t_stack *stack1)
{
	int	len;
	int	i;
	int	min_s;

	len = stack1->counter;
	min_s = stack1->stack[0];
	i = 0;
	while (i < len)
	{
		if (stack1->stack[i] < min_s)
			min_s = stack1->stack[i];
		i++;
	}
	return (min_s);
}

/* check if an stack it's sorting or no */

int	ft_check_sorting(t_stack *stack1)
{
	int	i;
	int	j;
	int	len;

	len = stack1->counter;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack1->stack[i] > stack1->stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
