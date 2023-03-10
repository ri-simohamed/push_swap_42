/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:03:55 by mrami             #+#    #+#             */
/*   Updated: 2023/03/09 16:15:18 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* sort an stack of 3 rondem number */

void	ft_sort_thri_num(t_stack *stack1)
{
	int	max_num;
	int	min_num;
	int	len;

	max_num = ft_get_max_of_stack(stack1);
	min_num = ft__get_min_of_stack(stack1);
	len = stack1->counter;
	if (max_num == stack1->stack[len - 1] && min_num == stack1->stack[1])
		ft_swap_to_a(stack1);
	if (max_num == stack1->stack[0] && min_num == stack1->stack[len - 1])
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
	if (min_num == stack1->stack[len - 1] && max_num == stack1->stack[1])
		ft_rotet_rev_a(stack1);
}

/* sort an stack then five number */

// void	ft_sort_five_num(t_stack *stack1, t_stack *stack2)
// {
// 	int	len;
// }
