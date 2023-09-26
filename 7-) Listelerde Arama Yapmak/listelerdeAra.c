/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listelerdeAra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:41:25 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 16:24:16 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Tek Bağlı Doğrusal Listelerde Arama Yapmak
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*search_node(t_list *head, char *content)
{
	t_list	*found;

	found = NULL;
	while (head)
	{
		if (head->content != content)
			head = head->next;
		else
		{
			found = head;
			break ;
		}
	}
	return (found);
}

int	main(void)
{
	t_list *head = malloc(sizeof(t_list));

	head->content = "First";
	head->next = NULL;

	t_list *first = malloc(sizeof(t_list));
	first->content = "Second";
	first->next = NULL;

	t_list *second = malloc(sizeof(t_list));
	second->content = "Third";
	second->next = NULL;

	head->next = first;
	head->next->next = second;

	char *content = "Second";
	int i = 1;
	t_list *tmp = head;
	while (tmp)
	{
		printf("%d-) %p\n", i, tmp);
		tmp = tmp->next;
		i++;
	}

	printf("%p", search_node(head, content));
}