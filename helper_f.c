/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:22:11 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 17:22:52 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * This function counts the elements in the list.
 */
int	count_elements(t_node **head1)
{
	int		element_count;
	t_node	*temp;

	element_count = 0;
	temp = *head1;
	while (temp != NULL)
	{
		element_count++;
		temp = temp->next;
	}
	return (element_count);
}

/**
 * This function is used to find min in the stack.
 */
int	find_min(t_node **head)
{
	int		min;
	t_node	*temp;

	min = (*head)->data;
	temp = *head;
	while (temp != NULL)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

/*---- Check is the stack is solved ---------------------------------------*/
/*---- if it is solved it will return 1 if it is not returns 0 ------------*/
int	check_if_stack_is_solved(t_node *head)
{
	while (head != NULL)
	{
		if (head->next != NULL && head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
