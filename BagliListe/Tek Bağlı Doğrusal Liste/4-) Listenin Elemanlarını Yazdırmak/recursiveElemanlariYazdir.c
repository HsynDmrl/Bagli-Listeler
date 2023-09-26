/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursiveElemanlariYazdir.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:18:34 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 14:35:50 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	print_node_recursive(t_list *head)
{
	static int	i;

	i = 1;
	if (!head)
		return ;
	else
	{
		printf("%d-) %s\n", i, head->content);
		i++;
		print_node_recursive(head->next);
	}
}

int	main(void)
{
	t_list *head = malloc(sizeof(t_list));
	head->content = "First";
	head->next = NULL;

	t_list *first = malloc(sizeof(t_list));
	first->content = "Second";
	first->next = NULL;

	head->next = first;

	print_node_recursive(head);
}