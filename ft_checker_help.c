/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:46:00 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 23:00:28 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* swap tow first element of the stack A */

void	ft_swap_to_a_check(t_stack *stack_a)
{
	int	size_a;

	size_a = stack_a->counter;
	if (size_a > 1)
		ft_swap(stack_a, size_a);
}
/* swap tow first element of the stack B */

void	ft_swap_to_b_check(t_stack *stack_b)
{
	int	size_b;

	size_b = stack_b->counter;
	if (size_b > 1)
		ft_swap(stack_b, size_b);
}

/* rotate the first element of stack A in the last of the stack. */

void	ft_rotet_a_check(t_stack *stack_a)
{
	int	size_a;

	size_a = stack_a->counter;
	if (size_a > 2)
		ft_rotate(stack_a, size_a);
}

/* rotate the first element of stack B in the last of the stack. */

void	ft_rotet_b_check(t_stack *stack_b)
{
	int	size_b;

	size_b = stack_b->counter;
	if (size_b > 2)
		ft_rotate(stack_b, size_b);
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
