/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:30:38 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:25:05 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Takes the first element at the top of stack_a and puts it at the top of b.
 * Does nothing if the stack_a is empty.
 */
void	push_b(t_node **head1, t_node **head2)
{
	t_node	*first_node;
	t_node	*temp;

	if (!(*head1))
		return ;
	first_node = *head1;
	if (*head1)
	{
		*head1 = (*head1)->next;
		if (!head2)
		{
			*head2 = first_node;
			(*head2)->next = NULL;
		}
		else
		{
			temp = *head2;
			(*head2) = first_node;
			(*head2)->next = temp;
		}
	}
	write(1, "pb\n", 3);
}

/**
 * Takes the first element at the top of stack_b and put it at the top of a.
 * Do nothing if stack_b is empty.
 */
void	push_a(t_node **head1, t_node **head2)
{
	t_node	*first_node;
	t_node	*temp;

	if (!(*head2))
		return ;
	first_node = *head2;
	if (*head2)
	{
		*head2 = (*head2)->next;
		if (!head1)
		{
			*head1 = first_node;
			(*head1)->next = NULL;
		}
		else
		{
			temp = *head1;
			(*head1) = first_node;
			(*head1)->next = temp;
		}
	}
	write(1, "pa\n", 3);
}

/**
 * ra (rotate a): Shift up all elements of stack_a by 1.
 * The first element becomes the las one.
 */
void	ra(t_node	**head1)
{
	t_node	*first_element;
	t_node	*second_element;
	t_node	*temp;

	first_element = *head1;
	second_element = (*head1)->next;
	temp = *head1;
	*head1 = second_element;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first_element;
	temp->next->next = NULL;
	write(1, "ra\n", 3);
}
