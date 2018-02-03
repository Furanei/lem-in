/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:58:44 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/03 12:08:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

unsigned long long	atoi_lem(char const *str)
{
	unsigned long long	i;
	unsigned long long	j;
	int 				neg;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	j = i;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && j == i)
	{
		neg = -1;
		i++;
	}
	j = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		j = j * 10 + (str[i] - 48);
		i++;
	}
	j *= neg;
	(j > 2147483647) ? ft_error("ERROR") : 0;
	return (j);
}

void				check_ant(t_lem *l)
{
	parse_comment(&*l);
	if (l->f & 0xFFFFFFFE || !(ft_isnumber(l->lmap[l->i],
	ft_strlen(l->lmap[l->i]))))
		ft_error("ERROR (ant_error)");
	if ((l->ant = atoi_lem(l->lmap[l->i])) <= 0)
		ft_error("ERROR (no_ant)");
	l->f += ANT;
}

int		check_room(t_lem *l)
{
	int i;

	i = 0;
	l->i++;
	while (l->lmap[l->i] != NULL)
	{
		parse_comment(&*l);
		if (ft_strchr(l->lmap[l->i], '-'))/////////a voir si je garde
			break;
		if (l->lmap[l->i][0] == 'L')
			ft_error("ERROR (room)");
		else if (search_sharp(l) == 2)
			parse_order(&*l);
		else if (!room_count_word(l->lmap[l->i], ' '))
			ft_error("ERROR (room)");
		else
			parse_room(&*l, 0);
		l->i++;
	}
	return (1);
}

void	malloc_ptr_pipe(t_lem *l)
{
	t_room		*tmp;

	tmp = l->room_list;
	while (tmp != NULL)
	{
		tmp->pipe = malloc(sizeof(void*) * l->nb_room);
		ft_bzero(tmp->pipe, sizeof(void*));
		tmp = tmp->next;
	}
}

void	check_error(t_lem *l)
{	
	check_ant(&*l);
	check_room(&*l);
	malloc_ptr_pipe(&*l);
	check_pipe(&*l);
}
