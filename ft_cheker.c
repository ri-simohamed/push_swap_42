/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:41:56 by mrami             #+#    #+#             */
/*   Updated: 2023/04/11 01:15:34 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* check Actions */

void	ft_check_actions(char *act, t_stack *stack1, t_stack *stack2)
{
	if (!ft_strncmp(act, "sa\n", 3))
		ft_swap_to_a_check(stack1);
	else if (!ft_strncmp(act, "sb\n", 3))
		ft_swap_to_b_check(stack2);
	else if (!ft_strncmp(act, "ra\n", 3))
		ft_rotet_a_check(stack1);
	else if (!ft_strncmp(act, "rb\n", 3))
		ft_rotet_b_check(stack2);
	else if (!ft_strncmp(act, "rra\n", 4))
		ft_rotet_rev_a_check(stack1);
	else if (!ft_strncmp(act, "rrb\n", 4))
		ft_rotet_rev_b_check(stack2);
	else if (!ft_strncmp(act, "pa\n", 3))
		ft_push(stack2, stack1);
	else if (!ft_strncmp(act, "pb\n", 3))
		ft_push(stack1, stack2);
	else if (!ft_strncmp(act, "ss\n", 3))
	{
		ft_swap_to_b_check(stack2);
		ft_swap_to_a_check(stack1);
	}
	else
		ft_print_error("Error:");
}

/* print 'OK' Or 'KO' */

void	ft_checker_print(t_stack *stack1)
{
	if (!ft_check_sorting(stack1) && stack1->counter != 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*action;

	stack_a.stack = 0;
	stack_b.stack = 0;
	stack_b.stack = 0;
	ft_split_to_atio(argc, argv, &stack_a);
	action = get_next_line(0);
	while (action != NULL)
	{
		ft_check_actions(action, &stack_a, &stack_b);
		free(action);
		action = get_next_line(0);
	}
	ft_checker_print(&stack_a);
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
