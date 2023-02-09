/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:35:16 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:32 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include "Mesh.hpp"
# include "Texture.hpp"

#define WIDTH 1500
#define HEIGHT 920

class Scop
{
	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//
	public:
		Scop();
		Scop(std::string name);
		Scop(Scop const &src);
		
		~Scop();
		
		Scop	&operator=(Scop const &rhs);

	//******************************************************************************************************//
	//												Getters										    		//
	//******************************************************************************************************//
	
	std::vector<GLfloat>	getVertices() const;
	std::vector<Mesh>		getMesh() const;
	Texture					getTexture(int i) const;
	
	//******************************************************************************************************//
	//											Public Functions								    		//
	//******************************************************************************************************//

	public:
		// void	initVariables();
		void	init();
		void	loadMesh(std::string const &path);
		void	loadTexture(std::string const &path, int i);

	//******************************************************************************************************//
	//											Private Functions								    		//
	//******************************************************************************************************//
	
	private:
		void	changeVector3ToGLfloat(std::vector<Vector3> &vertices);
		void	centerAxix(std::vector<GLfloat>	*_vertices, int verLen);
		// GLfloat	*saveMesh	(GLfloat *array, char *line);

	//******************************************************************************************************//
	//											Public Variables								    		//
	//******************************************************************************************************//

	public:
		GLFWwindow	*_window;

		Transform	_transform;
		Modifier	_modifier;
		KeyCount	_keyCount;

		float		_far = 100.0f;
		
		bool		_quit = true;
		
		bool framebufferResized = false; //- Stock framebuffer resized -//

	//******************************************************************************************************//
	//											Private Variables								    		//
	//******************************************************************************************************//
	
	private:
		std::vector<Mesh>		_mesh;
		std::vector<Texture>	_textures;
		std::vector<GLfloat>	_vertices;
		std::vector<GLuint>		_indices;
		// std::vector<GLfloat>	_vertices;
};

//******************************************************************************************************//
//											No Member Functions 							    		//
//******************************************************************************************************//

// Control //
void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void	mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void	resetTransform(void);
void	onKeyPress(void);

// Events //
int		events(void);

// Utils //
std::vector<char>   readFile(const std::string &filename);

#endif
