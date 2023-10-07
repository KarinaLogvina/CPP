/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:21:36 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 15:19:24 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main () {
    ScavTrap avanger("Stark");

	avanger.guardGate();
	for (int i = 0; i < 61; i++)
		avanger.attack("Loky");
	avanger.takeDamage(70);
	avanger.beRepaired(45);
	avanger.takeDamage(40);
	
	return (0);
}
