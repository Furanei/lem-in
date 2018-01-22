/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:54:23 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/21 20:40:40 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

int		get_next_word(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == c)
		{
			while (str[i] == c)
			{
				if (str == 0)
					return (0);
				i++;
			}
			return (i);
		}
		i++;
	}
	return (0);
}
