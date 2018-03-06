/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/05 20:46:23 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*ft_lstroomnew(void const *name, size_t size, int *f)
{
	t_room		*newroom;

	if (((newroom = (t_room*)ft_memalloc(sizeof(t_room))) == NULL)
		|| ((newroom->name = (char*)ft_memalloc(size + 1)) == NULL))
		ft_error_info(INFO, "malloc_error");
	ft_memcpy(newroom->name, name, size);
	if (*f & NEXTSTART)
	{
		newroom->spe = START;
		*f -= NEXTSTART;
	}
	else if (*f & NEXTEND)
	{
		newroom->spe = END;
		*f -= NEXTEND;
	}
	return (newroom);
}

void	add_room(t_lem *l, char *s, t_room *tmp, int size)
{
	char	*a;

	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strcmp((a = ft_strndup(s, size)), tmp->name) == 0)
				ft_error("ERROR (room)");
			ft_strdel(&a);
			if (tmp->next == NULL)
			{
				tmp->next = ft_lstroomnew(s,
					ft_strlen_c(s, ' '), &l->f);
				l->nb_room++;
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		l->room_list = ft_lstroomnew(s, size, &l->f);
		l->nb_room++;
	}
}

int		parse_room(t_lem *l, char *s, int len)
{
	t_room		*tmp;

	tmp = NULL;
	tmp = l->room_list;
	add_room(&*l, s, &*tmp, len);
	return (1);
}
