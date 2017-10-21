/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 02:13:28 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/22 00:15:45 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lm	init_lm(t_lm *l)
{
	// if (!(l = malloc(sizeof(t_lm))))
	// 	ft_error("ft_error malloc");
	l->s = NULL;
	l->i_buf = 0;
	return (*l);
}

void	free_lm(t_lm *l)
{
	free(l->s);
	l->s = NULL;
	l = NULL;
}

void	error_lem(t_lm *l)
{
	free_lm(l);
	l->ferror & ANT ? ft_error("error no ants") : 0;
	!(l->flag & (START + END)) ? ft_error("error") : 0;
}

int		main(void)
{
	t_lm	l;

	l = init_lm(&l);
	parsing(&l);

	free_lm(&l);
	// while (1);
	return (0);
}
