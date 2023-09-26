/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemanlariSay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:35:03 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 14:40:41 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	listLeng(t_list *head)
{
	int	i;

	i = 0;
	if (!head)
		return (i);
	else
	{
		while (head)
		{
			i++;
			head = head->next;
		}
	}
	return (i);
}

int	main(void)
{
	t_list	*head;
	t_list	*first;

	head = malloc(sizeof(t_list));
	head->content = "First";
	head->next = NULL;
	first = malloc(sizeof(t_list));
	first->content = "Second";
	first->next = NULL;
	head->next = first;
	printf("%d", listLeng(head));
}
