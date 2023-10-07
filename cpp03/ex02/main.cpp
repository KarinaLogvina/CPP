/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:21:36 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 15:34:12 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main () {
	FragTrap barney("Barney");

	barney.highFivesGuys();
	barney.attack("Ted");
	barney.takeDamage(20);
	barney.highFivesGuys();
	barney.beRepaired(83);
	barney.beRepaired(53);
	barney.takeDamage(93);
	barney.highFivesGuys();

	return (0);
}
