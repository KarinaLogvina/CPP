/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:21:36 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/09/30 19:02:40 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main () {
    ClapTrap *tmp1 = new ClapTrap("Dude");
    tmp1->attack("Iron man");
    tmp1->takeDamage(3);
    tmp1->beRepaired(4);
    tmp1->takeDamage(3);
    tmp1->attack("Hulk");

    delete tmp1;

    std::cout << std::endl;

    return(0);
}
