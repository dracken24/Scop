/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:47:16 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 10:55:12 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
# define TEXTURE_HPP

#include "../utils.hpp"

class Texture
{
	public:
		Texture();
		Texture(std::string path);
		Texture(const Texture &src);
		~Texture();

		Texture &operator=(Texture const &rhs);

		// Setters
		void	setId(GLuint id);
		void	setPath(std::string path);

		// Getters
		GLuint	getId(void) const;
		std::string	getPath(void) const;

	private:
		std::string     _name;
		std::string		_path;
		
		GLuint	_id;
};

#endif
