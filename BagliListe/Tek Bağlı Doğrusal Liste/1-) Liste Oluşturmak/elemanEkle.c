/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemanEkle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:20:44 by hdemirel          #+#    #+#             */
/*   Updated: 2023/09/26 12:24:00 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Tek Bağlı Doğrusal Liste Oluşturmak ve Eleman Eklemek

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

/*
Bağlı listeler içerisindeki düğümlerin yukarıdaki tanımlamayla iki öğesinin olduğu görülüyor.
Birinci öğe olan data, her türden veri içerebilir, örneğin telefon numaraları, TC kimlik numaraları vb. gibi.
İkinci öğe olan next, bir bağlı listede mutlaka bulunması gereken bir öğedir.
Dikkat edilirse struct s_list tipinde bir işaretçidir.
*/

int	main(void)
{
	struct s_list *head; // Henüz bellekte yer kaplamıyor

	head = (struct s_list *)malloc(sizeof(struct s_list));
		// Bellekte yer tahsis edildi.

	head->data = 5;    // listeye yeni eleman eklendi.
	head->next = NULL; // head'in next'ine null eklendi.

	head->next = (struct s_list *)malloc(sizeof(struct s_list));
		// Bir sonraki için bellekte yer tahsis edildi.
	head->next->data = 3;                                       
		// Yeni listeye yeni eleman eklendi.
	head->next->next = NULL;                                    
		// Yeni listeden sonra null eklendi.

	printf("%d", head->data);       // head'in datası yazdırıldı.
	printf("%d", head->next->data); // head'in next'inin datası yazdırıldı.
}