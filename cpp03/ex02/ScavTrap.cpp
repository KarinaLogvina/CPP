/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:23:53 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 13:44:15 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    this->_name = "Default name";
    this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
    this->_name = name;
    this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap & other) {
     std::cout << "Copy constructor called" <<  std::endl;
    *this = other;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
    if (this != & rhs)
    {
        std::cout << "Assignation operator called" << std::endl;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string & target) {
    if (energy_points && hit_points)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
        << " causing " << attack_damage << " points of damage!"<< std::endl;
        energy_points--;
    } 
    if (!energy_points)
    {
        std::cout << "ScavTrap doesn't have anough energy points to attack"<< std::endl;
    } 
    if (!hit_points) {
        std::cout << "ScavTrap doesn't have hit points to attack"<< std::endl;
    }
 }

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!"  << std::endl;
}

