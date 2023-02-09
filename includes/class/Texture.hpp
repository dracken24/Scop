/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:47:16 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 20:41:51 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HPP
# define TEXTURE_HPP

#include "../utils.hpp"

class Texture
{
	struct t_texture
	{
		int w, h, bpp, opp, sl, size;
		unsigned char *img;
	};
	
	public:
		Texture();
		Texture(std::string path);
		Texture(const Texture &src);
		~Texture();

		Texture &operator=(Texture const &rhs);

		// Setters
		void	setId(GLuint id);
		void	setPath(std::string path);
		void	setTexture(const char *filename);

		// Getters
		GLuint		getId(void) const;
		std::string	getPath(void) const;
		std::string	getName(void) const;

		t_texture	*getTexture(void);

		int		getImgSize(const char *path);
		
	private:
		void	getImage(const char *buffer, int i);
		void	readHeader(std::ifstream& file);

	private:
		std::string     _name;
		std::string		_path;
		// Vector2			_size;

		// unsigned char*	_img;
		t_texture 		_texBuff;
		
		GLuint	_id;
};

#endif
