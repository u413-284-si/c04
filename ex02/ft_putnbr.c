/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:05:51 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/14 21:05:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* Check for signature and return positive value for further calculation.
If minimal int -2147483648 entered, increase by one before returning
to enable further calculation. Set the variable min_flag 
(being pointed at) to 1.*/
int	ft_sign(int x, int *ptr)
{
	int	absolute;

	if (x >= 0)
	{
		absolute = x;
	}
	else
	{
		if (x == -2147483648)
		{
			x += 1;
			*ptr = 1;
		}
		absolute = -x;
		write(1, "-", 1);
	}
	return (absolute);
}

/* Count the number of digits */
int	ft_count(int y)
{
	int	counter;

	counter = 1;
	while (y > 9)
	{
		y /= 10;
		counter++;
	}
	return (counter);
}

/* Calculate power of 10 and return result*/
int	ft_power(int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= 10;
		power--;
	}
	return (result);
}

/* Retrieve digits starting from the first element by
dividing by the according power of 10, so that the 
desired digit is in the last place and retrieve it by
calculating the modulo. At last digit check the min_flag,
and if true increase digit by 1 (has been decreased before).*/
void	ft_print(int abs, int length, int min_flag)
{
	int		divisor;
	char	output;

	while (length > 0)
	{
		divisor = ft_power(length - 1);
		output = ((abs / divisor) % 10) + '0';
		if (length == 1 && min_flag)
			output += 1;
		write(1, &output, 1);
		length--;
	}
}

void	ft_putnbr(int nb)
{
	int	abs;
	int	length;
	int	min_flag;
	int	*ptr;

	min_flag = 0;
	ptr = &min_flag;
	abs = ft_sign(nb, ptr);
	length = ft_count(abs);
	ft_print(abs, length, min_flag);
}
