/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/03 12:06:18 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	save_map(t_lem *l)
{
	int 	ret;
	char			buff[BUFF_S + 1];

	l->map = ft_strndup("\0", 1);
	ft_bzero(buff, BUFF_S + 1);
	while ((ret = read(0, buff, BUFF_S)))
		l->map = ft_strnjoinfree(l->map, buff, ret, 'L');

	l->lmap = ft_strsplit(l->map, '\n');
}

int		main(void)
{
	t_lem		l;

	ft_bzero(&l, sizeof(t_lem));
	l.room_list = NULL;
	save_map(&l);
	check_error(&l);
	algo(&l);
	ft_printf("%s\n\n", l.map);
	print_ant(&l);
	printf("efwef\n");////////
	return(0);
}
