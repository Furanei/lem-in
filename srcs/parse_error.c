
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:58:44 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/21 20:52:54 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		next_line(t_lem *l)
{
	l->index += l->n;
	l->index += (l->index ? 1 : 0);
	l->n = ft_strlen_c(&l->map[l->index], '\n');
	l->s = ft_strndup(&l->map[l->index], l->n);
	return (1);
}

int		check_ant(t_lem *l)// OK
{
	next_line(&*l);
	iscomment(&*l);
	if (l->f & 0xFFFFFFFE || !(ft_isnumber(l->s, ft_strlen(l->s))))
		ft_error_info(INFO, "ant_error");
	if (!(l->ant = ft_atoi(l->s)))
		ft_error_info(INFO, "no_ant");
	return (1);
}

int		check_room(t_lem *l)
{
	next_line(&*l);
	while (!ft_strchr(l->s, '-'))
	{
		iscomment(&*l);
		if (l->s[0] == 'L')
			ft_error_info(INFO, "room_error");
		else if (search_sharp(l) == 2)
			printf("SHARP\n");
		else if (!room_count_word(l->s, ' '))
			ft_error_info(INFO, "room_error_2");
		next_line(&*l);
	}
	return (1);
}

int		check_pipe(t_lem *l)
{
	while (ft_strchr(l->s, '-'))
	{
		iscomment(&*l);
		printf("cw :%d\n", ft_count_word(l->s, '-'));
		if (ft_count_word(l->s, '-') != 2 || ft_strchr(l->s, ' '))
			ft_error_info(INFO, "pipe_error");
		next_line(&*l);
	}
	return (1);
}

void	check_error(t_lem *l)
{	
	check_ant(&*l) ? l->f += ANT : 0;
	check_room(&*l);
	check_pipe(&*l);
	ft_error_info(INFO, "END_PARSING_ERROR !");
}
