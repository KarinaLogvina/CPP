/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:23:50 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 11:47:10 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {
    public: 
        ScavTrap();
        ScavTrap(std::string const name);
		ScavTrap(ScavTrap & other);

        ScavTrap & operator=(ScavTrap const & rhs);
		void attack(const std::string & target);
		void guardGate();
        
        ~ScavTrap();
};

#endif
