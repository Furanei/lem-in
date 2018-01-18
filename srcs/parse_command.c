/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:38:12 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/18 03:08:23 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*start or end*/
// int		is_valid_command(char *s, t_lem *l)
// {
// 	if (ft_strcmp(s, "start"))
// 	{
// 		if (l->flag & START)
// 			ft_error("ERROR(double_start)");
// 		else
// 			l->flag += START;
// 		return (1);
// 	}
// 	else if (ft_strcmp(s, "end"))
// 	{
// 		if (l->flag & END)
// 			ft_error("ERROR(double_END)");
// 		else
// 			l->flag += END;
// 		return (2);
// 	}
// 	else
// 		return (0);
// }

// void	is_command(char *s, t_lem *l)
// {	
// 	if (is_valid_command(&s[2], &*l))
// 	{
// 		free(s);
// 	}
// }

int		search_sharp(t_lem *l)
{
	int n;

	n = 0;
	n += (l->s[0] == '#');
	n += (n ? (l->s[1] == '#'): 0);
	return (n);
}
