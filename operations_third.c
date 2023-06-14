/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:11:27 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:26:45 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa (swap a): Swaps the first 2 elements at the top of stack_a.
 * Does nothing if the is only one or no elements.
 */
void	swap_a(t_node **head1)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*third_element;

	if (!(*head1) || (*head1)->next == NULL)
		return ;
	first_element = *head1;
	second_element = (*head1)->next;
	third_element = (*head1)->next->next;
	*head1 = second_element;
	(*head1)->next = first_element;
	(*head1)->next->next = third_element;
	write(1, "sa\n", 3);
}

/**
 * sb (swap b): Swaps the first 2 elements at the top of stack_b.
 * Does nothing if the is only one or no elements.
 */
void	swap_b(t_node **head2)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*third_element;

	if (!(*head2) || (*head2)->next == NULL)
		return ;
	first_element = *head2;
	second_element = (*head2)->next;
	third_element = (*head2)->next->next;
	*head2 = second_element;
	(*head2)->next = first_element;
	(*head2)->next->next = third_element;
	write(1, "sb\n", 3);
}

/**
 * This function does both swap_a and swap_b in the same move.
 */
void	swap_both(t_node **head1, t_node **head2)
{
	swap_a(head1);
	swap_b(head2);
	write(1, "ss\n", 3);
}
