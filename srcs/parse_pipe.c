/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:49:08 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/04 07:30:43 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		strequ_room(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if ((!s1) || (!s2))
		return (0);
	while (s1 || s2)
	{
		if ((s1[i] == '-' && s2[i] == 0) || (s2[i] == '-' && s1[i] == 0))
			return (1);
		if (s1[i] != s2[i])
			return (0);
		if ((s1[i] == s2[i]) && (s1[i] == 0))
			return (1);
		i++;
	}
	return (0);
}

t_room	*get_room(char *s, t_room *r)
{
	while (r && (strequ_room(s, r->name) == 0))
	{
		r = r->next;
	}
	if (r == NULL)
		ft_error("ERROR");
	return (r);
}

void	parse_pipe(t_lem *l)
{
	int		j;
	int		i;
	t_room	*r1;
	t_room	*r2;

	j = 0;
	i = ft_strlen_c(l->lmap[l->i], '-');
	r1 = l->room_list;
	r2 = l->room_list;
	r1 = get_room(&l->lmap[l->i][j], &*r1);
	j = next_word(&*l, i, '-');
	r2 = get_room(&l->lmap[l->i][j], &*r2);
	r1->pipe[r1->npipe] = r2;
	r1->npipe++;
	r2->pipe[r2->npipe] = r1;
	r2->npipe++;
}

int		check_pipe(t_lem *l)
{
	while (l->lmap[l->i] != 0)
	{
		if (parse_comment(&*l) == 0)
			break ;
		if (ft_count_word(l->lmap[l->i], '-') != 2
			|| ft_strchr(l->lmap[l->i], ' '))
		{
			ft_error("ERROR");
		}
		parse_pipe(&*l);
		l->i++;
	}
	return (1);
}
