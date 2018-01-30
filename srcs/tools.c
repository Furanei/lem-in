/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:54:23 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/30 05:48:56 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		next_line(t_lem *l)
{
	l->index += l->size;
	if (l->index)
	{
		free(l->s);
		l->index = l->index + 1;
	}
	// printf("= |%s|\n", &l->map[l->index]), fflush(0);
	l->size = ft_strlen_c(&l->map[l->index], '\n');
	l->s = ft_strndup(&l->map[l->index], l->size);
	return (1);
}

int 	gne(t_lem *l)
{
	if (l->nline)
	{
		l->map = ft_strnjoinfree(l->map, "\n", ft_strlen(l->s), 'L');
		l->map = ft_strnjoinfree(l->map, l->s, ft_strlen(l->s), 'B');
	}
	else
	{
		l->map = ft_strdup(l->s);
		free(l->s);
	}
	return(get_next_line(0, &l->s));
}
