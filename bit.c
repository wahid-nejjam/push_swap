/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 04:34:49 by conoel            #+#    #+#             */
/*   Updated: 2019/02/06 04:39:08 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	decal_horizontal(char *tetri)
{
	int i;

	i = 0;
	while (i < 4) // je verifie tous les caracteres ( donc une ligne horizontale)
	{
		if (tetri[i] != '.')
			break ;
		i++;
	}
	if (i == 4)  // si les 4 caracteres sont vides
	{
		i = 0;
		while (i < 5)              // alors je decale tous les caracteres des lignes horizontalent (+5 parceque le /n)
		{
			tetri[i] = tetri[i + 5];
			tetri[i + 5] = tetri[i + 10];
			tetri[i + 10] = tetri[i + 15];
			tetri[i + 15] = '.';
			i++;
		}
		decal_horizontal(tetri);   // puis je rappelle ma fonction si jamais je peux encore decaler d'une ligne
	}
}

static void	decal_vertical(char *tetri)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] != '.')
			break ;
		i += 5;
	}
	if (i == 20)
	{
		i = 0;
		while (i < 20)
		{
			tetri[i] = tetri[i + 1];
			tetri[i + 1] = tetri[i + 2];
			tetri[i + 2] = tetri[i + 3];
			tetri[i + 3] = '.';
			i += 5;
		}
		decal_vertical(tetri);
	}
}
