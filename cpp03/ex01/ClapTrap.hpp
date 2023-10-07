/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:41:23 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 13:48:36 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    protected: 
        std::string _name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;

    public: 
        ClapTrap();
        ClapTrap(std::string const name);
		ClapTrap(ClapTrap & other);

        ClapTrap & operator=(ClapTrap const & rhs);
        
        void attack(const std::string & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        ~ClapTrap();
};

#endif
