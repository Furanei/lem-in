/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:21:12 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/22 00:38:11 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		parse_ants(t_lm *l, char *s)
{
	int  i;

	i = 0;
	if (!ft_isdigit(s[i]))
	{
		l->ferror += ANT;
		error_lem(l);
	}
	(l->ant = ft_atoi(s)) ? l->flag += ANT : (l->ferror += ANT); 
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0')
		error_lem(l);
}

void	extract_coordinates(t_lm *l, char *s)
{
	int i;

	i = 0;
	if (ft_isdigit(s[i]))
	{
		
	}

}

void	order_coor(t_lm *l, char *s)
{
	extract_coordinates(l, s);
	l->flag -= WAIT_ORDER;
}

void	parse_order(t_lm *l, char *s)
{
	int i;

	i = 2;
	if (l->flag & WAIT_ORDER)
		order_coor(l, s);		
	if (s[0] == '#' && s[1] == '#')
	{
		if (ft_strcmp("start", &s[i]) == 0)
		{
			i += ft_strlen("start");
			if (s[i])
			{
				error_lem(l);
			}
			l->flag += START;
		}
		else if (ft_strcmp("end", &s[i]) == 0)
		{
			i += ft_strlen("end");
			if (s[i])
			{
				error_lem(l);
			}
			l->flag += END;
		}
	}
	else
		return;
}

static void	branch_of_parse(t_lm *l, char *s)
{
	!(l->flag & ANT) ? parse_ants(l, s) : 0;
	(l->flag & (START + END)) != 0x60000000 || l->flag & WAIT_ORDER ? parse_order(l, s) : 0;
}

void	parsing(t_lm *l)
{
	char	*s;

	while ((get_next_line(0, &s) == 1))
	{
		branch_of_parse(&*l , s);
		if (l->s)
			s = ft_strnjoinfree(l->s, s, ft_strlen(s), 'B');
		l->s = ft_strnjoinfree(s, "\n", 1, 'L');
	}
	if (!l->s)
		error_lem(l);
	s = NULL;
	ft_printf("%d\n", l->ant);
	ft_printf("%b\n", l->flag);
}
