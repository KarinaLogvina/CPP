/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:13 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 15:22:32 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
		FragTrap(void);
		FragTrap(std::string const name);
		FragTrap(FragTrap & other);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);
		void highFivesGuys(void);
};

#endif
