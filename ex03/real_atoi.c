/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:50:17 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/22 14:27:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	real_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);			
}

int	main(void)
{
	char	str[] = "         - +54800-+2147483648t889+0";
	printf("Actual atoi: %d\n", atoi(str));
	printf("My atoi: %d\n", real_atoi(str));
	return (0);
}
