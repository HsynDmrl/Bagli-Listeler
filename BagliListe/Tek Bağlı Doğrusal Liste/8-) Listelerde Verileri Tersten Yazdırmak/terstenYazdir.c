/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terstenYazdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:42 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 16:33:41 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Tek Bağlı Doğrusal Listelerde Verileri Tersten Yazdırmak
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	print_node(t_list *head)
{
	int	i;

	i = 1;
	if (!head)
	{
		printf("Eleman yok");
		return ;
	}
	else
	{
		while (head)
		{
			printf("%d-) %s\n", i, head->content);
			head = head->next;
			i++;
		}
	}
}

struct s_list	*addhead(struct s_list *head, char *first)
{
	struct s_list	*tmp;

	tmp = (struct s_list *)malloc(sizeof(struct s_list));
	tmp->content = first;
	tmp->next = head;
	head = tmp;
	return (head);
}

void	print_reverse(t_list *head)
{
	t_list	*tmp;
	t_list	*head2;

	tmp = head;
	head2 = NULL;
	while (tmp)
	{
		head2 = addhead(head2, tmp->content);
		tmp = tmp->next;
	}
	print_node(head2);
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

	print_reverse(head);
}