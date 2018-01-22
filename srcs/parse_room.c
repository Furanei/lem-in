/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:20:57 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/22 04:46:30 by mbriffau         ###   ########.fr       */
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

int		parse2_room(t_lem *l, int o)
{
	char **str;
	int	i;
	int b;

	i = 0;
	b = 0;
	printf("-3b-\n");
	str = ft_strsplit(l->s, ' ');
	printf("-3c-\n");
	i = ft_strlen(&str[0][0]);
	printf("%d\n", i);
	b = ft_strlen(&str[2][0]);
	printf("%d %d\n", i, b);
	if (!(ft_isnumber(str[1], ft_strlen(str[1])) || ft_isnumber(str[2], ft_strlen(str[2]))))
	{
		printf("-fec-\n");
		ft_error_info(INFO, "room");
	}
	printf("-3t-\n");
	printf("-5-\n");
	if (o)
	{
		if (!ft_strcmp(&l->s[2], "start"))
		{
			l->f += START;
		}
		else if (!ft_strcmp(&l->s[2], "start"))
		{
			l->f += END;
		}
		gne(&*l);
		return (parse2_room(&*l, 0));
	}
	printf("parse_%s\n", l->s);
	return (gne(&*l));
}
