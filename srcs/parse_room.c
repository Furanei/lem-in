/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/24 16:50:19 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*ft_lstroomnew(void const *name, size_t size, size_t option)
{
	t_room		*newroom;
	
	if ((newroom = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	if ((newroom->name = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(newroom->name, name, size);
	newroom->spe = option;
	newroom->next = NULL;
	newroom->child = NULL;
	return (newroom);
}

/*si le premier ou dernier char est = c, ou si le nombre de 
str mots est different de 3 return 0 */
int			room_count_word(const char *s, char c)
{
	int		i;

	i = 0;
	if (s[0] == c || s[ft_strlen(s) - 1] ==c)
		return(0);
	if (ft_count_word(s, c) != 3)
		return(0);
	return (1);
}

int		next_word(t_lem *l, int i, char c)
{
	while (l->s[i] != '\0' && l->s[i] != c)
		i = i + 1;
	if ((l->s[i] == '\0') || ((l->s[i + 1] == '\0' || l->s[i + 1] == c)))
		ft_error_info(INFO, l->s);
	return (i + 1);
}

void	ft_test_room_list(t_room **rlst)
{
	t_room *tmp;

	tmp = *rlst;
	printf("test start\n");
	printf("(*rlst)->");
	while (tmp)
	{
		printf("[%s]->", tmp->name);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

int		parse_room(t_lem *l, int option)
{
	int			i;
	t_room		*tmp;

	parse_comment(&*l);
	tmp = *l->room_list;
	i = ft_strlen_c(l->s, ' ');
	if (tmp == NULL)
		*l->room_list = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);
	else
	{
		while (tmp)
		{
			if (ft_strncmp(l->s, (tmp)->name, i) == 0)//duplicate
				ft_error_info(INFO, l->s);
			if (tmp->next == NULL)
			{
				tmp->next = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////;
				break;
			}
			tmp = tmp->next;
		}
	}
	i = next_word(&*l, i, ' ');
	if (!ft_isdigit(l->s[i]))
		ft_error_info(INFO, "room");
	i = next_word(&*l, i, ' ');
	if (!ft_isdigit(l->s[i]))
		ft_error_info(INFO, "letter_in_coordinate");
	// tmp = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////
	// while (*l->room_list)
	// -dans le premier mot est deja dans la room_list > doublon
	// 	- sinon aller au bou de la la room list et add
	// - prendre l'element suivant puis regarder si c'est bien un int
	// - prendre le 3eme element puis veriffier que c'est un int;
	return (1);
}
