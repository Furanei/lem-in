/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:43:25 by mbriffau          #+#    #+#             */
/*   Updated: 2018/01/19 01:44:52 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_error_info(char *file, char *func, int line, char const *s)
{
	ft_putstr("\033[1;31mERROR\033[1;37m: ");
	ft_putstr(file);
	ft_putstr("\033[0m(file) \033[1;37m");
	ft_putstr(func);
	ft_putstr("()\033[0m(function)\033[1;37m L");
	ft_putnbr(line);
	ft_putstr("\033[0m(line)\033[1;37m");
	ft_putstr("\033[0m: ");
	ft_putstr(s);
	ft_putstr("\n");
	exit(-1);
}
