/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/23 23:23:15 by mbriffau         ###   ########.fr       */
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

int		next_word(char *s, int i, char c)
{
	while (s[i] != '\0' && s[i] != c)
		i = i + 1;
	if ((s[i] == '\0') || ((s[i + 1] == '\0'
		|| s[i + 1] == c)))
		ft_error("ERROR (room)");
	return (i + 1);
}

void	room_start_end(t_lem *l, int *option)
{
	if (l->f & STARTEND)
	{
		if (l->f & START)
		{
			*option = START;
			l->f -= START;
		}
		else if (l->f & END)
		{
			*option = END;
			l->f -= END;
		}
		l->f -= STARTEND;
	}
}

void	add_room(t_lem *l, char *s, t_room *tmp, int size, int option)
{
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(s, tmp->name, size) == 0)
				ft_error("ERROR (room)");
			if (tmp->next == NULL)
			{
				tmp->next = ft_lstroomnew(s,
					ft_strlen_c(s, ' '), option);
				l->nb_room++;
				break ;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		l->room_list = ft_lstroomnew(s, size, option);
		l->nb_room++;
	}
}
