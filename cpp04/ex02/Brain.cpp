/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:04:58 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/21 18:05:14 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default Brain constructor called" << std::endl;
};

Brain::Brain(Brain const & other) {
    std::cout << "Copy Brain constructor called" << std::endl;
    for (size_t i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    };
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs) {
    if (this != &rhs) {
		for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
	return *this;
}

