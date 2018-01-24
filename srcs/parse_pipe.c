/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:49:08 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/24 16:56:02 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	parse_pipe(t_lem *l)
{

	int			i;
	t_room		*r1;
	t_room		*r2;

	parse_comment(&*l);
	r1 = *l->room_list;
	r2 = *l->room_list;
	i = ft_strlen_c(l->s, '-');
	while (l->s)
	{
		while (r1 && (ft_strncmp(l->s, (r1)->name, i) != 0))
			r1 = r1->next;
		if (r1)
		{
			l->s = l->s + next_word(&*l, i, '-');
			while (r2 && (ft_strncmp(l->s, (r2)->name, i) != 0))
				r2 = r2->next;
			if (r2)
			{
				printf("%s-link-%s\n", (r1)->name, (r2)->name);/////////continue
			}
		}

	ft_error_info(INFO, "END");		
	}
}
////////////////////////////////////////////////////////////
	// {
	// 	while (tmp)
	// 	{
	// 		if (ft_strncmp(l->s, (tmp)->name, i) == 0)//duplicate
	// 			ft_error_info(INFO, l->s);
	// 		if (tmp->next == NULL)
	// 		{
	// 			tmp->next = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////;
	// 			break;
	// 		}
	// 		tmp = tmp->next;
	// 	}
	// }
	// i = next_word(&*l, i, ' ');
	// if (!ft_isdigit(l->s[i]))
	// 	ft_error_info(INFO, "room");
	// i = next_word(&*l, i, ' ');
	// if (!ft_isdigit(l->s[i]))
		// ft_error_info(INFO, "letter_in_coordinate");
	// tmp = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////
	// while (*l->room_list)
	// -dans le premier mot est deja dans la room_list > doublon
	// 	- sinon aller au bou de la la room list et add
	// - prendre l'element suivant puis regarder si c'est bien un int
	// - prendre le 3eme element puis veriffier que c'est un int;
// }

// void 	search_pipe(t_lem *l, char *s)
// {
// 	if (((ft_count_word(s, '-') != 2) || !search_sharp(l, s)))
// 		ft_error_info(INFO, "room");
// }
