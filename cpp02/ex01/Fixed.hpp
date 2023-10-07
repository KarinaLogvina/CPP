/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:22 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/09/29 17:09:24 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _floatingPointNumber;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(Fixed const & other);
        Fixed & operator=(Fixed const & rhs);
        ~Fixed();

        int		getRawBits( void ) const;
        void	setRawBits( int const raw );

        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream & operator<<( std::ostream & os, Fixed const & num );

#endif
