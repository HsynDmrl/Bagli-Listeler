/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SonunaEkle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:55:48 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 12:57:53 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef	struct s_list
{
	int data;
	struct s_list *next;
} t_list;

struct s_list *addlast(struct s_list *head)
{
	if(!head)
		return 0;
	
	while (head)
	{
		if (!(head->next))
			return head;
		head = head->next;
	}
	return head;
}

void print(struct s_list *head) 
{
	if(head == NULL) 
	{
		printf("Listede eleman yok");
		return;
	}
	struct s_list *temp2 = head;
	while(temp2!= NULL) 
	{
		printf("%d\n", temp2->data);
		temp2 = temp2->next;
	}
}
int	main()
{
	struct s_list *head = (struct s_list *)malloc(sizeof(struct s_list));
	struct s_list *first = (struct s_list *)malloc(sizeof(struct s_list));
	struct s_list *second = (struct s_list *)malloc(sizeof(struct s_list));

	head->data = 10;
	first->data = 12;
	second->data = 13;
	
	head->next = first;
	head->next->next = second;
	head->next->next->next = NULL;
	
	addlast(head);
	print(head);
}