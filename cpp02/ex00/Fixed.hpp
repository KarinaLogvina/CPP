/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:48 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/09/29 17:09:49 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _rawBits;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(Fixed const & other);
        ~Fixed();

        Fixed & operator=(Fixed const & rhs);
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
};


#endif
