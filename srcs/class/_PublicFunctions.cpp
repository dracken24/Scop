/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _PublicFunctions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:55:55 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 00:20:14 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/_ProgramGestion.hpp"

extern ProgramGestion app;

//******************************************************************************************************//
//												Init										    		//
//******************************************************************************************************//

void	ProgramGestion::initVariables(int argc, char **argv)
{
	_deltaTime = 0.0f;
	
	app._translate.x = 0.0f;
	app._translate.y = 0.0f;
	app._translate.z = 0.0f;
	app._rotate.x = 0.0f;
	app._rotate.y = 0.0f;
	app._rotate.z = 0.0f;

	for (int it = 0; it < argc; it++)
	{
		if (strcmp(strrchr(argv[it], '.'), ".obj") == 0)
		{
			app._obj.push_back({argv[it], strrchr(argv[it], '/'), app.getObjSize(argv[it])});
		}
		if (strcmp(strrchr(argv[it], '.'), ".png") == 0 || strcmp(strrchr(argv[it], '.'), ".jpg") == 0)
		{
			std::string tmp;
			if (strcmp(strrchr(argv[it], '.'), ".png") == 0)
				tmp = "png";
			else if (strcmp(strrchr(argv[it], '.'), ".jpg") == 0)
				tmp = "jpg";

			app._textures.push_back({argv[it], strrchr(argv[it], '/'), app.getImgSize(argv[it]), tmp});
		}
		else if (strcmp(strrchr(argv[it], '.'), ".obj") != 0)
			std::cout << RED << "Error: File type not supported: " << argv[it] << RESET << std::endl;
	}

	_far = app.getMaxObjSize(app._obj.at(0)) * 1.2f;
	_scale.x = _far;
	_scale.y = _far;
	_scale.z = _far;
	_zoomModifier = _far / 10;
}

//******************************************************************************************************//
//										 		Gestion								  		    		//
//******************************************************************************************************//


int	events(GLFWwindow *window)
{
	glfwSetKeyCallback(window, key_callback);	                // Key Hook //
	glfwSetMouseButtonCallback(window, mouse_button_callback);	// Mouse Hook //;
	glfwSetScrollCallback(window, scroll_callback);	            // Scroll Hook //;
	glfwSetCursorPosCallback(window, cursor_position_callback);	// Cursor Hook //;
	glfwSetDropCallback(app.window, drop_callback);
	
	return (0);
}

void	listAll()
{
	if (app._obj.size() > 0)
	{
		std::cout << "\n-----------------------------------------------------------------" << std::endl;
		for (int k = 0; k < app._obj.size(); k++)
		{
			std::cout << YELLOW << "\nDropped Obj Name  [" << k << "]  : " << app._obj[k].objName << std::endl;
			std::cout << "Dropped Obj Path  [" << k << "]  : " << app._obj[k].objPath << std::endl << std::endl;
			std::cout << "Dropped Obj X [" << k << "]      : " << app._obj[k].objSize.x << std::endl;
			std::cout << "Dropped Obj Y [" << k << "]      : " << app._obj[k].objSize.y << std::endl;
			std::cout << "Dropped Obj Z [" << k << "]      : " << app._obj[k].objSize.z << RESET << std::endl << std::endl;
		}
	}
	if (app._textures.size() > 0)
	{
		std::cout << "-----------------------------------------------------------------" << std::endl;
		for (int k = 0; k < app._textures.size(); k++)
		{
			std::cout << YELLOW << "\nDropped Img Name  [" << k << "]  : " << app._textures[k].imgName << std::endl;
			std::cout << "Dropped Img Path  [" << k << "]  : " << app._textures[k].imgPath << std::endl;
			std::cout << "Dropped Img Type  [" << k << "]  : " << app._textures[k].imgType << std::endl;
			std::cout << "Dropped Img Width [" << k << "]  : " << app._textures[k].imgSize.x << std::endl;
			std::cout << "Dropped Img Height[" << k << "]  : " << app._textures[k].imgSize.y << RESET << std::endl << std::endl;
		}
		std::cout << "-----------------------------------------------------------------" << std::endl;
	}
}

void	drop_callback(GLFWwindow* window, int count, const char** paths)
{
	static int i = 0;

    // std::cout << "Dropped " << count << std::endl;
	std::cout << std::endl;
    for (int it = 0; it < count; it++)
    {
		if (strcmp(strrchr(paths[it], '.'), ".obj") == 0)
		{
			Vector3 tmp = app.getObjSize(paths[it]);
			
			app._obj.push_back({paths[it], strrchr(paths[it], '/'), tmp});
			if (count == 1)
			{
				app._far = app.getMaxObjSize(app._obj.at(app._obj.size() - 1)) * 1.2f;
				app._scale.x = app._far;
				app._scale.y = app._far;
				app._scale.z = app._far;
				app._zoomModifier = app._far / 10;
				app.changeMesh(app._obj.at(app._obj.size() - 1));
				app._objIndex = app._obj.size() - 1;
			}
		}
		else if (strcmp(strrchr(paths[it], '.'), ".png") == 0 || strcmp(strrchr(paths[it], '.'), ".jpg") == 0)
		{
			std::string tmp;
			if (strcmp(strrchr(paths[it], '.'), ".png") == 0)
				tmp = "png";
			else if (strcmp(strrchr(paths[it], '.'), ".jpg") == 0)
				tmp = "jpg";
			
			app._textures.push_back({paths[it], strrchr(paths[it], '/'), app.getImgSize(paths[it]), tmp});
			// app._textureIndex = app._textures.size() - 1;
			if (count == 1)
				app.changeTexture(app._textures.at(app._textures.size() - 1));
		}
        else
            std::cout << RED << "Error: File type not supported: " << paths[it] << RESET << std::endl;
    }

	listAll();
	
	// for (int i = 0; i < app._textures.size(); i++)
	// {
	// 	std::cout << GREEN << "Texture [" << i << "] : " << app._textures[i].imgName << RESET << std::endl;
	// }
	std::cout << "Choose Mesh or Texture" << std::endl;
		std::cout << "1 - Texture" << std::endl;
		std::cout << "2 - Mesh" << std::endl;
}


void	ProgramGestion::choice()
{
	int				quit = 0;
	int				index = 0;
	std::string		choose;
	while (quit == 0)
	{
		std::cout << "Choose Mesh or Texture" << std::endl;
		std::cout << "1 - Texture" << std::endl;
		std::cout << "2 - Mesh" << std::endl;

		std::cin >> choose;
		index = atoi(choose.c_str());

		if (choose.compare("q") == 0 || choose.compare("Q") == 0)
		{
			_quit = false;
		}
		else if (index == 1)
			quit = chooseTexture();
		else if (index == 2)
			quit = chooseObj();
		else
		{
			std::cout << RED << "Error: Wrong choice !!" << RESET << std::endl;
		}
		// choose = 0;
	}
}

// Thread to choose texture //
int		ProgramGestion::chooseObj()
{
	std::cout << std::endl;
	
	for (int i = 0; i < _obj.size(); i++)
	{
		std::cout << GREEN << "Mesh [" << i << "] : " << _obj[i].objName << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	int			nbrIndex;
	std::string	objIndex;
	std::cout << BLUE << "'l' or 'L' for list all files\n" << RESET << std::endl;
	std::cout << "Choose a Mesh: ";
	std::cin >> objIndex;
	nbrIndex = atoi(objIndex.c_str());

	std::cout << std::endl << std::endl;
	
	if (objIndex.compare("q") == 0 || objIndex.compare("Q") == 0)
	{
		_quit = false;
		return (1);
	}
	else if (objIndex.compare("l") == 0 || objIndex.compare("L") == 0)
	{
		listAll();
	}
	else if ((nbrIndex < 0 || nbrIndex > _obj.size() - 1) && isdigit(objIndex[0]) != 0)
	{
		std::cout << RED << "Error: Mesh index out of range" << RESET << std::endl << std::endl;
	}
	else if (isdigit(objIndex[0]) == 0)
	{
		std::cout << RED << "Error: index not numeric" << RESET << std::endl << std::endl;
	}
	else
	{
		std::cout << "Texture [" << nbrIndex << "] : " << _obj[nbrIndex].objName << std::endl;
		_mesh = true;
		_objIndex = nbrIndex;
		
		return (1);
	}

	return (0);
}

// Thread to choose texture //
int		ProgramGestion::chooseTexture()
{
	std::cout << std::endl;
	
	for (int i = 0; i < _textures.size(); i++)
	{
		std::cout << GREEN << "Texture [" << i << "] : " << _textures[i].imgName << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	int			nbrIndex;
	std::string	textureIndex;
	std::cout << BLUE << "'l' or 'L' for list all files\n" << RESET << std::endl;
	std::cout << "Choose a texture: ";
	std::cin >> textureIndex;
	nbrIndex = atoi(textureIndex.c_str());

	std::cout << std::endl << std::endl;
	
	if (textureIndex.compare("q") == 0 || textureIndex.compare("Q") == 0)
	{
		_quit = false;
		return (1);
	}
	else if (textureIndex.compare("l") == 0 || textureIndex.compare("L") == 0)
	{
		listAll();
	}
	else if ((nbrIndex < 0 || nbrIndex > _textures.size() - 1) && isdigit(textureIndex[0]) != 0)
	{
		std::cout << RED << "Error: Texture index out of range" << RESET << std::endl << std::endl;
	}
	else if (isdigit(textureIndex[0]) == 0)
	{
		std::cout << RED << "Error: index not numeric" << RESET << std::endl << std::endl;
	}
	else
	{
		std::cout << "Texture [" << nbrIndex << "] : " << _textures[nbrIndex].imgName << std::endl;
		_texture = true;
		_textureIndex = nbrIndex;
		return (1);
	}

	return (0);
}

// Create texture image //
void	ProgramGestion::changeTexture(Texture2D	texture)
{
	// Destroy old texture //
	vkQueueWaitIdle(graphicsQueue);
	
    vkDestroyImageView(device, textureImageView, nullptr);
    vkDestroyImage(device, textureImage, nullptr);
    vkFreeMemory(device, textureImageMemory, nullptr);
	vkDestroySampler(device, textureSampler, nullptr);
	vkDestroyDescriptorPool(device, descriptorPool, nullptr);
	
	// Create new texture //
	createTextureImage(texture);
	createTextureImageView();
	createTextureSampler();
	createDescriptorPool();
	createDescriptorSets();
	createCommandBuffers();
}

void	ProgramGestion::changeMesh(Obj mesh)
{
	// Clear previous mesh data //
    vkQueueWaitIdle(graphicsQueue);
    vkFreeMemory(device, vertexBufferMemory, nullptr);
    vkDestroyBuffer(device, vertexBuffer, nullptr);
    vkFreeMemory(device, indexBufferMemory, nullptr);
    vkDestroyBuffer(device, indexBuffer, nullptr);

    vertices.clear();
    indices.clear();

    // Load new mesh data //
    loadModel(mesh);
    createVertexBuffer();
    createIndexBuffer();
    createCommandBuffers();

	app._far = app.getMaxObjSize(app._obj.at(app._objIndex)) * 1.2f;
	app._scale.x = app._far;
	app._scale.y = app._far;
	app._scale.z = app._far;
	app._zoomModifier = app._far / 10;
	// app._objIndex = app._obj.size() - 1;
}
