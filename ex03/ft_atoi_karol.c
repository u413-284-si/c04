/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_karol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:36:35 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/13 22:37:20 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(char *str)
{
	int result;
	int revert;
	int n;

	result = 0;
	n = 0;
	revert = 1;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == ' ')
		n++;
	while (str[n] == '-' || str[n] == '+')
		if (str[n++] == '-')
			revert *= -1;
	result = 0;
	while (str[n] >= '0' && str[n] <= '9')
		result = result * 10 + str[n++] - '0';
	return (result * revert);

}

