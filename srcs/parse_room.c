/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/18 03:54:24 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*si le premier ou dernier char est = c, ou si le nombre de 
str mots est different de 3 return 0 */
int			room_count_word(const char *s, char c)
{
	int		i;

	i = 0;
	if (s[0] == c || s[ft_strlen(s) - 1] ==c)
		return(0);
	if (ft_count_word(s, c) != 3)
		return(0);
	return (1);
}

void	parse_room(t_lem *l, int o)
{
	if (o)
	{
		if (!ft_strcmp(&l->s[2], "start"))
		{
			//////////////////////
		}
		else if (!ft_strcmp(&l->s[2], "start"))
		{
			//ewgewf
		}
	}
	printf("parse_%s\n", l->s);
}

// int		save_room(t_lem *l, char *name, int option)
// {
// 	save room et pram start or end
// }

void	search_room(t_lem *l)
{
	if (l->s[0] == 'L')
		ft_error_info(INFO, "room name(L)");
	else if ((room_count_word(l->s, ' ')))
	{
		printf("OKROOM\n");
		parse_room(&*l , 0);
	}
	else if (search_sharp(l) == 2)
	{
		l->f += STARTEND;
		parse_room(&*l, 1);
	}
	else if (search_sharp(l))
		gne(&*l);
	else
		ft_error_info(INFO, "room");
}