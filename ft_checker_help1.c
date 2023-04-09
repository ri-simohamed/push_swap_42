/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_help1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:47:53 by mrami             #+#    #+#             */
/*   Updated: 2023/04/08 23:00:07 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* rotate rev to stack A */

void	ft_rotet_rev_a_check(t_stack *stack_a)
{
	int	len;

	len = stack_a->counter;
	if (len > 1)
		ft_rotet_rev(stack_a, len);
}

/* rotate rev to stack B */

void	ft_rotet_rev_b_check(t_stack *stack_b)
{
	int	len;

	len = stack_b->counter;
	if (len > 1)
		ft_rotet_rev(stack_b, len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (!s1[i] || !s2[i])
			break ;
		i++;
	}
	return (0);
}

/* swap tow element */

void	ft_swap(t_stack *stact_a, int size)
{
	int	tmp;

	(void)size;
	tmp = stact_a->stack[0];
	stact_a->stack[0] = stact_a->stack[1];
	stact_a->stack[1] = tmp;
}

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
