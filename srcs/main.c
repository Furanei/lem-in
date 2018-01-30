/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/30 05:16:42 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void free_lem(t_lem	*l)
{
	free(l->map);
}

void save_map(t_lem *l)
{
	int i;

	while (get_next_line(0, &l->s))
	{
		i = ft_strlen(l->s);
		if (l->nline)
		{
			l->map = ft_strnjoinfree(l->map, "\n", i, 'L');
			l->map = ft_strnjoinfree(l->map, l->s, i, 'B');
		}
		else
		{
			l->map = ft_strdup(l->s);
			free(l->s);
		}
		l->nline++;
	}
	free(l->map);
	l->lmap = ft_strsplit(l->map, '\n');
}

int		main(void)
{
	t_lem		l;

	ft_bzero(&l, sizeof(t_lem));
	l.room_list = NULL;
	save_map(&l);
	check_error(&l);
	// free_lem(&l);
	return(0);
}
