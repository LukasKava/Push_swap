/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_up_to_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:44:55 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 18:30:42 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Solves less than three numbers.
 */
void	solve_less_than_three(t_node **head)
{
	if ((*head)->data > (*head)->next->data)
		swap_a(head);
}

static void	cases(t_node **head)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	if (third->data > second->data && third->data > first->data)
		swap_a(head);
	else if (third->data < first->data && third->data > second->data)
		ra(head);
	else if (third->data < second->data && first->data > second->data)
	{
		swap_a(head);
		rra(head);
	}
}

/**
 * Solves 3 numbers.
 * There are specifically five cases that can happen.
 * CASE_1: 2,1,3 --sa--->  1,2,3
 * CASE_2: 3,2,1 --sa--->  2,3,1 --rra--> 1,2,3
 * CASE_3: 3,1,2 --ra--->  1,2,3
 * CASE_4: 1,3,2 --sa--->  3,1,2 --ra--->  1,2,3
 * CASE_5: 2,3,1 --rra-->  1,2,3
 */
void	solve_three_nbr(t_node **head)
{
	if (check_if_stack_is_solved(*head) == 1)
		return ;
	if ((*head)->data > (*head)->next->data)
	{
		cases(head);
	}
	else
	{
		if ((*head)->next->next->data < (*head)->data)
			rra(head);
		else
		{
			swap_a(head);
			ra(head);
		}
	}
}
