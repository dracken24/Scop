/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:14:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 14:39:16 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/_ProgramGestion.hpp"

// #define STB_IMAGE_IMPLEMENTATION

ProgramGestion app;

// Thread to choose texture //
void	threadChooseTexture()
{
	if (app._thread == true && app._quit == true)
	{
		// std::cout << "Thread" << std::endl;
		std::thread	chooseTextureThread(std::bind(&ProgramGestion::choice, &app));
		chooseTextureThread.detach();
		app._thread = false;
	}
	if (app._texture == true)
	{
		// std::cout << "Texture" << std::endl;
		app.changeTexture(app._textures.at(app._textureIndex));
		app._texture = false;
		app._mesh = false;
		app._thread = true;
	}
	if (app._mesh == true)
	{
		// std::cout << "Texture" << std::endl;
		app.changeMesh(app._obj.at(app._objIndex));
		app._mesh = false;
		app._texture = false;
		app._thread = true;
	}
}

void mainLoop()
{
	while (app._quit == true && glfwWindowShouldClose(app.window) != true)
	{
		glfwPollEvents();

		events(app.window);		// Events //
		onKeyPress();			// Key gestion //

		threadChooseTexture();	// Thread to choose texture //
		
		app.drawFrame();		// Draw on screen //
        
        app.useFPS();			// FPS gestion //
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		try 
		{
			app.initVariables(argc, argv);
			app.init("BANKAI");

			app.setFPS(60);

			mainLoop();
			
			app.cleanup();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cout << RED << "Usage: ./scop [file.obj] [texture file.png or .jpg or ...]" << RESET << std::endl;
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}
