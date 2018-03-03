/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:49:08 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/03 19:23:57 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	malloc_ptr_pipe(t_lem *l)
{
	t_room		*tmp;

	tmp = l->room_list;
	while (tmp != NULL)
	{
		if (!(tmp->pipe = malloc(sizeof(void*) * l->nb_room)))
			exit(1);
		ft_bzero(tmp->pipe, sizeof(void*));
		tmp = tmp->next;
	}
}

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

void	duplicate_pipe(char *s, t_room *r)
{
	int		i;

	i = 0;
	while (i < r->npipe)
	{
		if (strequ_room(s, r->pipe[i]->name) == 1)
			ft_error("ERROR (duplicate pipe)");
		i++;
	}
}

t_room	*valid_room(char *s, t_room *r)
{
	while (r && (strequ_room(s, r->name) == 0))
		r = r->next;
	if (r == NULL)
		ft_error("ERROR");
	return (r);
}

void	parse_pipe(t_lem *l, char *s)
{
	t_room	*r1;
	t_room	*r2;

	r1 = l->room_list;
	r2 = l->room_list;
	if (!(r1->npipe < l->nb_room))
		ft_error("ERROR");
	r1 = valid_room(s, &*r1);
	r2 = valid_room(&s[ft_strlen_c(s, '-') + 1], &*r2);
	duplicate_pipe(s, r2);
	duplicate_pipe(&s[ft_strlen_c(s, '-') + 1], r1);
	r1->pipe[r1->npipe] = r2;
	r1->npipe++;
	r2->pipe[r2->npipe] = r1;
	r2->npipe++;
}
