/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <alfgarci@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:21:36 by alfgarci          #+#    #+#             */
/*   Updated: 2022/08/11 10:17:43 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numdigs(int n)
{
	int	i;
	int	num;

	i = 10;
	num = 1;
	if (n < 0)
		num++;
	while (n / i != 0)
	{
		num++;
		i *= 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int		i;
	int		is_neg;
	int		num_digs;
	char	*cad;

	i = -1;
	is_neg = 0;
	num_digs = get_numdigs(n);
	cad = (char *)malloc((num_digs + 1) * sizeof(char));
	if (!cad)
		return (NULL);
	if (n < 0)
	{
		cad[0] = '-';
		n *= -1;
		is_neg = 1;
	}
	while (++i < num_digs - is_neg)
	{
		cad[num_digs - (i + 1)] = (n % 10) + 48;
		printf("%d\n", (n % 10));
		n /= 10;
	}
	cad[i] = '\0';
	return (cad);
}
/*
int	main()
{
	int n = 123456;
	printf("Numero en str: $%s$", ft_itoa(n));
	return (0);
}*/