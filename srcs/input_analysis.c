/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analysis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:45:56 by mbriffau          #+#    #+#             */
/*   Updated: 2018/03/02 00:26:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		isvalid_comment(char *s)
{
	if (s != 0 && s[0] == '#')
		return(1);
	return (0);
}

int		isvalid_command(char *s)
{
	if (s != 0 && (ft_strlen(s) > 3))
	{
		if (s[0] == '#' && s[1] == '#')
		{
			if (ft_strequ(&s[2], "start"))
				return (1);
			if (ft_strequ(&s[2], "end"))
				return (2);
		}
	}
	return (0);
}

int		isvalid_ant_number(char *s)
{
	int nb;
	if ((ft_isnumber(s, ft_strlen(s))))
		if ((nb = atoi_lem(s)) > 0)
			return (1);
	return (0);
}

int		strchrrev(char *s, int size, char c)
{
	while (size && (s[size] != c))
		size--;
	return (size + 1);
}

int		isvalid_room(char *s)
{
	int		i;
	int		len;

	if (s != 0 && s[0] != 'L')
	{
		len = ft_strlen(s);
		i = strchrrev(s, (len - 1), ' ');
		if (ft_isnumber(&s[i], (len - i)))
		{
			if (s[i - 1] == ' ' && (i > 3) && (s[i - 2] != ' '))
			{
				len = i - 2;
				i = strchrrev(s, len, ' ');
				if (ft_isnumber(&s[i], (len - i + 1)) && i > 1)
				{
					i -= 2;
					if (s[i] != ' ')
						return (i + 1);
				}
			}
		}
	}
	return (0);
}

int		isvalid_pipe(char *s)
{
	if (ft_count_word(s, '-') == 2)// et room trouve dans la liste
		return (1);
	return (0);
}
