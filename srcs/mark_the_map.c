/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:40:06 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/01 20:06:38 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** La fonction verifie toutes salles les voisins de home et les marquent
** a la valeur de home +1 si elles ne sont pas visitees.
*/

t_room		*visit_neighbors(t_room *home, t_room *wire)
{
	int		i;

	i = 0;
	while (i < home->npipe)
	{
		if (home->pipe[i]->file == 0)
		{
			wire->thread = home->pipe[i];
			wire->thread->file = home->file + 1;
			wire = wire->thread;
		}
		i++;
	}
	return (wire);
}

/*
** La fonction marque toutes les salles en partant de end, en fonction de leur
** distance avec END. END est a 1, les salles proches voisines 2 , ect ...
** jusqu'a trouver START.
*/

t_room		*mark_the_map(t_room *home)
{
	t_room	*wire;

	wire = home;
	home->file = 1;
	while (home != NULL)
	{
		if (home->spe & START)
			return (home);
		wire = visit_neighbors(home, wire);
		home = home->thread;
	}
	ft_error("ERROR (no path)");
	return (0);
}
