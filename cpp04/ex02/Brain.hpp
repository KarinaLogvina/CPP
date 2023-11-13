/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:03:54 by urosby            #+#    #+#             */
/*   Updated: 2023/10/21 14:04:41 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
    private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const & other);
		~Brain(void);

		Brain & operator=(Brain const & rhs);
};

#endif