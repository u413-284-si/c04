/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:55:52 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/14 23:42:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* 
   Ignores initial whitespaces (including form feed, tabs, newline, carriage
   return), turns signature at each -, retrieves first number
   encountered and ignores anything following
 */

int	ft_atoi(char *str)
{
	int	base;
	int	sign;
	int	i;

	base = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		base = base * 10 + str[i++] - '0';
	return (base * sign);
}

//int	main(void)
//{
//	char	str[] = "   ++-----003087-2147483648t889+0";
//	printf("%d\n", ft_atoi(str));
//	return (0);
//}
