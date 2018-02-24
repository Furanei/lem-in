/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/24 20:11:06 by mbriffau         ###   ########.fr       */
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

// void	room_start_end(t_lem *l, int *option)
// {
// 	if (l->f & NEXTSTART)
// 	{
// 		*option = START;
// 		l->f -= NEXTSTART;
// 	}
// 	else if (l->f & NEXTEND)
// 	{
// 		*option = END;
// 		l->f -= NEXTEND;
// 	}
// }

void	add_room(t_lem *l, char *s, t_room *tmp, int size)
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

int					parse_room(t_lem *l, char *s, int len)
{
	t_room		*tmp;

	tmp = NULL;
	tmp = l->room_list;
	// size = ft_strlen_c(s, ' ');
	// room_start_end(&*l, &option);
	add_room(&*l, s, &*tmp, len);
	// size = next_word(s, size, ' ');
	// // if (!ft_isnumber(&s[size], ft_strlen_c(&s[size], ' ')))
	// // 	ft_error_info(INFO, "room");
	// size = next_word(s, size, ' ');
	// if (!ft_isnumber(&s[size], ft_strlen_c(&s[size], ' ')))
	// 	ft_error("ERROR (coor)");
	return (1);
}




















