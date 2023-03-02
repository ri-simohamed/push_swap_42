/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:47:31 by mrami             #+#    #+#             */
/*   Updated: 2023/03/02 17:30:09 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* rotate the first element of stack B in the last of the stack. */

void	ft_rotet_b(t_stack *stack_b, int size_b)
{
	size_b = stack_b->counter;
	if (size_b > 2)
	{
		ft_rotate(stack_b, size_b);
		write(1, "rb\n", 3);
	}
	else
		write(1, "rb\n", 3);
}

/* rotete the last elment of an array in the first */

void	ft_rotet_rev(t_stack *stack_rv, int len)
{
	int	i;
	int	temp;

	temp = stack_rv->stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack_rv->stack[i] = stack_rv->stack[i - 1];
		i--;
	}
	stack_rv->stack[0] = temp;
}
