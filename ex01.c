/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 11:35:13 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/10/07 13:33:20 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*le but de ce programme est de determiner si un nombre est divisible ou non par un autre*/


intmain(void)
{
  int nombre; /*declaration des variables nombre et diviseur, on declare des "cases" dans lesquelles on peut mettre une valeur*/
  int diviseur;

  nombre = 2;
  diviseur = 6;
  if (nombre % diviseur == 0) /*le symbole % signifie modulo, soit le resultat de a % b, est le reste de la division de a par b, ici nous testons si le reste est nul*/
    printf("%d est un diviseur de %d.\n", diviseur, nombre);/*si le reste est nul, alors le nombre est divisible sinon, il ne l'est pas*/
  else
    printf("%d n'est pas un diviseur de %d.\n", diviseur, nombre);
  return (0);
}
