/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:19 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 15:31:53 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_name = "Default name";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	this->_name = name;;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap & other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	if (this != & rhs)
    {
        std::cout << "Assignation operator called" << std::endl;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " ask about High Five!" << std::endl;
}


FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}
