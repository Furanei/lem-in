/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 02:14:53 by mbriffau          #+#    #+#             */
/*   Updated: 2017/10/22 00:27:22 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/ft_printf.h"

# define ANT	(1 << 31)
# define START	(1 << 30)
# define END	(1 << 29)
# define ROOM	(1 << 28)
# define PATH	(1 << 27)
# define WAIT_ORDER	(1 << 26)

typedef struct	s_lm
{
	char	*s;
	int		i_buf;
	int		fd;
	int		flag;
	int		ferror;
	int		ant;

}				t_lm;

void	parsing(t_lm *l);
void	error_lem(t_lm *l);

#endif