/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:44:06 by sqiu              #+#    #+#             */
/*   Updated: 2022/09/13 23:02:30 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(long int nb, int base, char *radix)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= base)
	{
		ft_putnbr(nb / base, base, radix);
		ft_putnbr(nb % base, base, radix);
	}
	else
		ft_putchar(radix[nb]);
}

// Check for doubles; + or -; and more than one base sign
int	input_check(char *base, int length)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (length < 2)
		return (0);
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			else if (base[i] == '+' || base[i] == '-')
				return (0);
			else if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Covering the edge case with long int
void	ft_putnbr_base(int nbr, char *base)
{
	int			length;
	long int	nbr_aux;

	length = str_len(base);
	nbr_aux = nbr;
	if (input_check(base, length))
		ft_putnbr(nbr_aux, length, base);
}

// int	main(int argc, char **argv)
// {	
// 	int	nbr = 2147483647; // Edge case: -2147483648

// 	(void) argc;

// 	ft_putnbr_base(nbr, argv[1]);
// 	return (0);
// }
