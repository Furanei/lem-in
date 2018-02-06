/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:43:13 by mbriffau          #+#    #+#             */
/*   Updated: 2018/02/06 07:05:48 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	save_map(t_lem *l)
{
	int		len;
	size_t	i;
	char	*s;

	i = 0;
	if (!(l->map = ft_strndup("\0", 1)))
		exit(1);
	while (get_next_line(0, &s) > 0)
	{
		len = ft_strlen(s);
		if (i++)
		{
			if (!(l->map = ft_strnjoinfree(l->map, "\n", 1, 'L')))
				exit(1);
		}
		if (!(l->map = ft_strnjoinfree(l->map, s, len, 'B')))
			exit(1);
	}
	l->lmap = ft_strsplit(l->map, '\n');
}

void	check_error(t_lem *l)
{
	check_ant(&*l);
	check_room(&*l);
	malloc_ptr_pipe(&*l);
	check_pipe(&*l);
}

int		main(void)
{
	t_lem	l;

	ft_bzero(&l, sizeof(t_lem));
	l.room_list = NULL;
	save_map(&l);
	check_error(&l);
	algo(&l);
	ft_printf("%s\n\n", l.map);
	print_ant(&l);
	return (0);
}
