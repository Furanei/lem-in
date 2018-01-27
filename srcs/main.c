/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/27 02:23:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"


void save_map(t_lem *l)
{
	get_next_line(0, &l->s);
	while(gne(&*l))
		l->nline++;
	if (!(l->order = malloc(sizeof(char) * l->nline + 1)))
		ft_error_info(INFO, "malloc");
	ft_bzero(l->order, l->nline + 1);
}

int		main(void)
{
	t_lem		l;

	init_struct(&l);// inititialise la structure t_lem
	save_map(&l);
	printf("---save_map---\n%s\n-----------\n\n", l.map);
	check_error(&l);
	parse(&l);
	return(0);
}

void	parse(t_lem *l)
{
	check_error(&*l);

	ft_putstr("\n----ECHO----\n");
	ft_putstr(l->s);
}