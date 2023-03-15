/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:03:55 by mrami             #+#    #+#             */
/*   Updated: 2023/03/15 16:47:39 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* sort number last then thrie number */

void	ft_thriesorting(t_stack *stack1, int max_num, int min_num)
{
	if (max_num == stack1->stack[stack1->counter - 1]
		&& min_num == stack1->stack[1])
		ft_swap_to_a(stack1);
	if (max_num == stack1->stack[0]
		&& min_num == stack1->stack[stack1->counter - 1])
	{
		ft_swap_to_a(stack1);
		ft_rotet_rev_a(stack1);
	}
	if (max_num == stack1->stack[0] && min_num == stack1->stack[1])
		ft_swap_to_a(stack1);
	if (min_num == stack1->stack[0] && max_num == stack1->stack[1])
	{
		ft_swap_to_a(stack1);
		ft_rotet_a(stack1);
	}
	if (min_num == stack1->stack[stack1->counter - 1]
		&& max_num == stack1->stack[1])
		ft_rotet_rev_a(stack1);
}

/* sort an stack of 3 rondem number */

void	ft_sort_thri_num(t_stack *stack1)
{
	int	max_num;
	int	min_num;

	max_num = ft_get_max_of_stack(stack1);
	min_num = ft__get_min_of_stack(stack1);
	if (stack1->counter < 3)
	{
		if (min_num == stack1->stack[1])
			ft_swap_to_a(stack1);
	}
	else
		ft_thriesorting(stack1, max_num, min_num);
}

/* sort five randem number */

void	ft_sort_five(t_stack *stack1, t_stack *stack2)
{
	int	index_min;

	while (stack1->counter > 3)
	{
		index_min = ft_index_of_min(stack1);
		if (index_min == 0)
		{
			ft_push(stack1, stack2);
			write(1, "pb\n", 3);
		}
		else if (index_min == 1)
			ft_swap_to_a(stack1);
		else if (index_min >= stack1->counter / 2)
			ft_rotet_rev_a(stack1);
	}
	ft_sort_thri_num(stack1);
	ft_push(stack2, stack1);
	write(1, "pa\n", 3);
	ft_push(stack2, stack1);
	write(1, "pa\n", 3);
}
