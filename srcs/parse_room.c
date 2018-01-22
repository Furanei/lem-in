/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 23:23:49 by mbriffau         ###   ########.fr       */
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
	printf("ewgwegewrgerge\n");
	newroom->spe = option;
	printf("ewgwegewrgerge\n");
	newroom->next = NULL;
	printf("EWWWWW\n");
	newroom->child = NULL;
	printf("ewgwegewrgerge\n");
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

int		next_word(t_lem *l, int i)
{
	while (l->s[i] != '\0' && l->s[i] != ' ')
		i = i + 1;
	if ((l->s[i] == '\0') || ((l->s[i + 1] == '\0' || l->s[i + 1] == ' ')))
		ft_error_info(INFO, l->s);
	return (i + 1);
}

int		parse_room(t_lem *l, int option)
{
	int			i;
	t_room		*tmp;

	tmp = *l->room_list;
	i = ft_strlen_c(l->s, ' ');
	while (tmp)
	{
		if (ft_strnequ(l->s, (tmp)->name, i))
			ft_error_info(INFO, "room_doublon");
		if (tmp->next == NULL)
			tmp->next = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////;
		tmp = tmp->next;
	}
	i = next_word(&*l, i);
	if (!ft_isdigit(l->s[i]))
		ft_error_info(INFO, "room");
	i = next_word(&*l, i);
	if (!ft_isdigit(l->s[i]))
		ft_error_info(INFO, "room");
	printf("ewgwegewrgerge\n");
	// tmp = ft_lstroomnew(l->s, ft_strlen_c(l->s, ' '), option);/////////////
	// while (*l->room_list)

	printf("ENDENDEND\n");



	// -dans le premier mot est deja dans la room_list > doublon
	// 	- sinon aller au bou de la la room list et add
	// - prendre l'element suivant puis regarder si c'est bien un int
	// - prendre le 3eme element puis veriffier que c'est un int;
	return (1);
}
