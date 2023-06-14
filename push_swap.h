/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:27:32 by lkavalia          #+#    #+#             */
/*   Updated: 2022/06/06 23:22:52 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*---- HEADERS ----*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*---- STRUCT ----*/

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_node;

/*---- Function Prototypes ----------------------------------------------*/

int				*main_checker(int argv, char **argc);

/*---- Function used to create stack_a. Located in create_stack.c -------*/

t_node			*c_full_stack(t_node *head1, int *stack_a, int len);

/*---- Helper functions. Located in helper_f.c ---------------------------*/

int				count_elements(t_node **head1);
int				find_min(t_node **head);
int				check_if_stack_is_solved(t_node *head);

/*---- Move functions used to sort the stack. ----------------------------*/
/*---- Located in operations.c operations_second.c operations_third.c-----*/

void			push_b(t_node **head1, t_node **head2);
void			push_a(t_node **head1, t_node **head2);
void			swap_a(t_node **head1);
void			swap_b(t_node **head2);
void			swap_both(t_node **head1, t_node **head2);
void			ra(t_node **head1);
void			rb(t_node **head2);
void			rotate_both(t_node **head1, t_node **head2);
void			rra(t_node **head1);
void			rrb(t_node **head2);
void			rrr_both(t_node	**head1, t_node	**head2);

/*---- Functions to sort small stacks <= 5 nbr. ---------------------------*/
/*---- Located in small_sort.c and solve_up_to_three.c --------------------*/

void			solve_less_than_three(t_node **head);
void			solve_three_nbr(t_node **head);
void			solve_five_nbr(t_node **head1, t_node **head2, int count);

/*---- Function for radix algorithm. Located in radix.c -------------------*/

void			radix_sort(t_node **head1, t_node	**head2);

#endif