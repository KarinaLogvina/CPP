/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:44:36 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/04 19:42:14 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Defaul name"), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
};


ClapTrap::ClapTrap(std::string const name) : _name(name), hit_points(10), energy_points(10), attack_damage(0) {
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;    
}

ClapTrap::ClapTrap(ClapTrap & other) {
     std::cout << "Copy constructor called" <<  std::endl;
    *this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
    if (this != & rhs)
    {
        std::cout << "Assignation operator called" << std::endl;
        this->hit_points = rhs.hit_points;
        this->energy_points = rhs.energy_points;
        this->attack_damage = rhs.attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string & target) {
    if (energy_points && hit_points)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
        << " causing " << attack_damage << " points of damage!"<< std::endl;
        energy_points--;
    } 
    if (!energy_points)
    {
        std::cout << "ClapTrap doesn't have anough energy points to attack"<< std::endl;
    } 
    if (!hit_points) {
        std::cout << "ClapTrap doesn't have hit points to attack"<< std::endl;
    }
 }

 void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points)
    {
         std::cout << "ClapTrap " << _name << " was attacked with " << amount<< " points of damage!"<< std::endl;
         if (hit_points > amount) {
            std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!"<< std::endl;
            hit_points -= amount;
         } else {
            hit_points = 0;
            std::cout << "ClapTrap " << _name << " dedad!" << std::endl;
            
         }
    } else {
        std::cout << "ClapTrap " << _name << " already dedad!" << std::endl;
    }  
 }

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points && hit_points)
    {
        std::cout << "ClapTrap " << _name << " repared "<< amount << " hit points." << std::endl;
        energy_points--;
        hit_points += amount;
        if (hit_points > 10)
            hit_points = 10;
    }
    if (!energy_points)
        std::cout << "ClapTrap " << _name << " cant be repared because no energy point left." << std::endl;
    if (!hit_points)
        std::cout << "ClapTrap " << _name << " cant be repared because no hit points left." << std::endl;
}
 

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}
