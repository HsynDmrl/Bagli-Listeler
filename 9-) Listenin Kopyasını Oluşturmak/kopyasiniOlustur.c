/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kopyasiniOlustur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:34:21 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 17:22:32 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*cons(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		printf("Bellek tahsisi hatasi\n");
		exit(1);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

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

t_list	*copy_node(t_list *head)
{
	t_list	*dest;
	t_list	*temp;

	dest = NULL;
	t_list *current = head;
		// Başlangıç düğümünü işaret eden bir işaretçi oluşturun
	while (current != NULL)
	{
		t_list *new_node = cons(current->content); // Yeni düğümü oluşturun
		if (dest == NULL)
		{
			dest = new_node; // İlk düğümü ayarlayın
		}
		else
		{
			temp = dest;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node; // Sonraki düğümü bağlayın
		}
		current = current->next; // Bir sonraki düğüme geçin
	}
	return (dest);
}

int	main(void)
{
	t_list *head = malloc(sizeof(t_list));

	head->content = "Head";
	head->next = NULL;

	t_list *first = malloc(sizeof(t_list));
	first->content = "First";
	first->next = NULL;

	head->next = first;

	printf("%p\n", head);
	printf("%p", copy_node(head));
}