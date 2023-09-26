/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ikiListeyiBirlestir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:59:12 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 17:23:21 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Tek Bağlı Doğrusal Listelerde İki Listeyi Birleştirmek

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	cat_node(struct s_list *head, struct s_list *head2)
{
	struct s_list	*tmp;

	if (!head)
		head = head2;
	else
	{
		tmp = head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = head2;
	}
}

void	print_node(struct s_list *head)
{
	if (!head)
	{
		printf("eleman yok");
		return ;
	}
	else
	{
		while (head)
		{
			printf("%s\n", head->content);
			head = head->next;
		}
	}
}

int	main(void)
{
	struct s_list *head = malloc(sizeof(t_list));
	head->content = "Head";
	head->next = NULL; // head'in sonunu NULL olarak ayarlayın

	struct s_list *second = malloc(sizeof(t_list));
	second->content = "Second";
	second->next = NULL;

	head->next = second;

	struct s_list *head2 = malloc(sizeof(t_list));
	head2->content = "Head2";
	head2->next = NULL;

	struct s_list *second2 = malloc(sizeof(t_list));
	second2->content = "Second2";
	second2->next = NULL;

	head2->next = second2;

	print_node(head);
	cat_node(head, head2);
	print_node(head);

	return (0);
}