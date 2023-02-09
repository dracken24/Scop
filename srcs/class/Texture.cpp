/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:48:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 20:42:20 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

//******************************************************************************************************//
//										Constructor - Destructor							    		//
//******************************************************************************************************//

Texture::Texture()
{
	// std::cout << "Default Texture constructor called" << std::endl;
}

Texture::Texture(std::string path) :
_path(path),
_name(path.substr(path.find_last_of("/") + 1))
{
	// Texture	*tmp = new Texture(*this);

	// *this = *tmp;
	// _texBuff.img = stbi_load(path.c_str(), &_texBuff.w, &_texBuff.h, &_texBuff.bpp, 0);
	
	// std::cout << "Texture constructor called" << std::endl;
}

Texture::Texture(const Texture &src)
{
	*this = src;
}

Texture::~Texture()
{
	// delete _texBuff.img;
	// delete this;
	// std::cout << "Texture destructor called" << std::endl;
}

Texture &Texture::operator=(Texture const &rhs)
{
	if (this != &rhs)
	{
		this->_path = rhs._path;
		this->_name = rhs._name;
		this->_id = rhs._id;
		this->_texBuff = rhs._texBuff;
	}
	return *this;
}

//******************************************************************************************************//
//												Setters										    		//
//******************************************************************************************************//

void	Texture::setId(GLuint id)
{
	this->_id = id;
}

void	Texture::setPath(std::string path)
{
	this->_path = path;
}





void error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

void	Texture::readHeader(std::ifstream& file)
{

    file.seekg(18, std::ios::beg);
    file.read(reinterpret_cast<char*>(&_texBuff.w), 4);
    file.read(reinterpret_cast<char*>(&_texBuff.h), 4);
    file.seekg(2, std::ios::cur);
    file.read(reinterpret_cast<char*>(&_texBuff.bpp), 2);
    _texBuff.opp = _texBuff.bpp / 8;
    _texBuff.sl = _texBuff.w * _texBuff.opp;
    _texBuff.w = _texBuff.w < 0 ? -_texBuff.w : _texBuff.w;
    _texBuff.h = _texBuff.h < 0 ? -_texBuff.h : _texBuff.h;
    _texBuff.size = _texBuff.sl * _texBuff.h;

	std::cout << "width: " << _texBuff.w << std::endl;
	std::cout << "height: " << _texBuff.h << std::endl;
	std::cout << "bpp: " << _texBuff.bpp << std::endl;
	std::cout << "opp: " << _texBuff.opp << std::endl;
	std::cout << "sl: " << _texBuff.sl << std::endl;
	std::cout << "size: " << _texBuff.size << std::endl;
}

void	Texture::getImage(const char *buffer, int i)
{
    int h = 0;
    int size = _texBuff.size * 2;
	
    _texBuff.img = new unsigned char[size];
    while (i >= 0)
	{
        i -= _texBuff.sl;
        int j = 0;
        while (j < _texBuff.sl)
		{
            _texBuff.img[h + j] = buffer[i + j + 2];
            _texBuff.img[h + j + 1] = buffer[i + j + 1];
            _texBuff.img[h + j + 2] = buffer[i + j];
            j += 3;
        }
        h += _texBuff.sl;
    }
}

// int	Texture::getImgSize(const char *path)
// {
//     int width;
//     int height;
//     int channels;
//     unsigned char *data = stbi_load(path, &width, &height, &channels, 0);
//     if (data)
//     {
//         stbi_image_free(data);
// 		// std::cout << "width: " << width << std::endl;
// 		// std::cout << "height: " << height << std::endl;
// 		// std::cout << width * height  << std::endl;
//         return (width * height);
//     }
//     else
//     {
//         std::cout << "Failed to load texture" << std::endl;
//         return (0);
//     }
// }

void	Texture::setTexture(const char *filename)
{
	std::ifstream file;
    file.open(filename, std::ios::binary);
    if (!file)
		error("bmp file opening failed.");
		
    readHeader(file);
    char *buffer = new char[_texBuff.size];
    file.seekg(54, std::ios::beg);
    file.read(buffer, _texBuff.size);
	std::cout << "1" << std::endl;
    getImage(buffer, _texBuff.size);
    delete[] buffer;
    file.close();
}

//******************************************************************************************************//
//												Getters										    		//
//******************************************************************************************************//

GLuint	Texture::getId(void) const
{
	return this->_id;
}

std::string	Texture::getPath(void) const
{
	return this->_path;
}

std::string	Texture::getName(void) const
{
	return this->_name;
}

Texture::t_texture	*Texture::getTexture(void)
{
	return (&_texBuff);
}
