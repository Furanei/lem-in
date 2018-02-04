/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/04 07:38:10 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*ft_lstroomnew(void const *name, size_t size, size_t option)
{
	t_room		*newroom;

	if (((newroom = (t_room*)ft_memalloc(sizeof(t_room))) == NULL)
		|| ((newroom->name = (char*)ft_memalloc(size + 1)) == NULL))
		ft_error_info(INFO, "malloc_error");
	ft_memcpy(newroom->name, name, size);
	newroom->spe = option;
	return (newroom);
}

/*
**si le premier ou dernier char est = c, ou si le nombre de
** mots est different de 3, return 0.
*/

int		room_count_word(const char *s, char c)
{
	int		i;

	i = 0;
	if (s[0] == c || s[ft_strlen(s) - 1] == c)
		return (0);
	if (ft_count_word(s, c) != 3)
		return (0);
	return (1);
}

int		next_word(t_lem *l, int i, char c)
{
	while (l->lmap[l->i][i] != '\0' && l->lmap[l->i][i] != c)
		i = i + 1;
	if ((l->lmap[l->i][i] == '\0') || ((l->lmap[l->i][i + 1] == '\0'
		|| l->lmap[l->i][i + 1] == c)))
		ft_error("ERROR (room)");
	return (i + 1);
}

void	room_start_end(t_lem *l, int option)
{
	if (l->f & STARTEND)
	{
		if (l->f & START)
		{
			option = START;
			l->f -= START;
		}
		else if (l->f & END)
		{
			option = END;
			l->f -= END;
		}
		l->f -= STARTEND;
	}
}

int		parse_room(t_lem *l, int option)
{
	int			size;
	t_room		*tmp;

	tmp = NULL;
	parse_comment(&*l);
	tmp = l->room_list;
	size = ft_strlen_c(l->lmap[l->i], ' ');
	// room_start_end(&*l, option);
	if (l->f & STARTEND)
	{
		if (l->f & START)
		{
			option = START;
			l->f -= START;
		}
		else if (l->f & END)
		{
			option = END;
			l->f -= END;
		}
		l->f -= STARTEND;
	}
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(l->lmap[l->i], tmp->name, size) == 0)
				ft_error("ERROR (room)");
			if (tmp->next == NULL)
			{
				tmp->next = ft_lstroomnew(l->lmap[l->i],
					ft_strlen_c(l->lmap[l->i], ' '), option);
				l->nb_room++;
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		l->room_list = ft_lstroomnew(l->lmap[l->i], size, option);
	}
	size = next_word(&*l, size, ' ');
	if (!ft_isdigit(l->lmap[l->i][size]))
		ft_error_info(INFO, "room");
	size = next_word(&*l, size, ' ');
	if (!ft_isdigit(l->lmap[l->i][size]))
		ft_error("ERROR (coor)");
	return (1);
}
