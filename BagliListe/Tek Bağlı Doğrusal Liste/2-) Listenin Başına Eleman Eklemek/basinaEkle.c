/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tekBagliDogrusal1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:22:00 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 11:37:23 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Tek Bağlı Doğrusal Listenin Başına Eleman Eklemek

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

struct s_list	*addhead(struct s_list *head, int first)
{
	struct s_list	*tmp;

	tmp = (struct s_list *)malloc(sizeof(struct s_list));
	tmp->data = first;
	tmp->next = head; // tmp'in next'i şimdi head'i gösteriyor.
	head = tmp; // head artık tmp'in adresini tutuyor, eklenen düğüm listenin başı oldu.
	//free(tmp); // leaks(sızıntı) hatasını önlemek için kullanılır şimdilik gerekli değil.
	return (head);
}

int	main(void)
{
	struct s_list *head = (struct s_list *)malloc(sizeof(struct s_list));

	head->data = 15;
	head->next = NULL;

	int first = 42;
	printf("Before = %p\n", head);             
		// Fonksiyona gönderilmeden önce head'in adresi yazdırıldı.
	printf("After  = %p", addhead(head, first));
		// Fonksiyona gönderildikten sonra head'in adresi yazdırıldı.
}