/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:04:42 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/19 02:04:24 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/lem_in.h"

int main(int ac, char **av)
{
	char	**ss;
	int		i;

	i = 0;
	if (ac == 2)
	{
		ss = ft_strsplit(av[1], ' ');
		while (ss[i])
		{
			printf("%s\n", ss[i]);
			i++;
		}
	}
	return (0);
}
