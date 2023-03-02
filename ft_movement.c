/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:24:43 by mrami             #+#    #+#             */
/*   Updated: 2023/03/02 17:34:19 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* swap tow element */

void	ft_swap(t_stack *stact_a, int size)
{
	int	tmp;

	(void)size;
	tmp = stact_a->stack[0];
	stact_a->stack[0] = stact_a->stack[1];
	stact_a->stack[1] = tmp;
}

/* swap tow first element of the stack A */

void	ft_swap_to_a(t_stack *stack_a, int size_a)
{
	size_a = stack_a->counter;
	if (size_a > 1)
	{
		ft_swap(stack_a, size_a);
		write(1, "sa\n", 3);
	}
	else
		write(1, "sa\n", 3);
}
/* swap tow first element of the stack B */

void	ft_swap_to_b(t_stack *stack_b, int size_b)
{
	size_b = stack_b->counter;
	if (size_b > 1)
	{
		ft_swap(stack_b, size_b);
		write(1, "sb\n", 3);
	}
	else
		write(1, "sb\n", 3);
}

/* rotate the first element in the last of an array */

void	ft_rotate(t_stack *stack_r, int len)
{
	int	i;
	int	temp;

	temp = stack_r->stack[0];
	i = 1;
	while (i < len)
	{
		stack_r->stack[i - 1] = stack_r->stack[i];
		i++;
	}
	stack_r->stack[len - 1] = temp;
}

/* rotate the first element of stack A in the last of the stack. */

void	ft_rotet_a(t_stack *stack_a, int size_a)
{
	size_a = stack_a->counter;
	if (size_a > 2)
	{
		ft_rotate(stack_a, size_a);
		write(1, "ra\n", 3);
	}
	else
		write(1, "ra\n", 3);
}
