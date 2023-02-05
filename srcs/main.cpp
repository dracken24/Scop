/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:14:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/04 22:28:57 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/_ProgramGestion.hpp"

// #define STB_IMAGE_IMPLEMENTATION

ProgramGestion app;

void mainLoop()
{
	while (app._quit == true && glfwWindowShouldClose(app.window) != true)
	{
		glfwPollEvents();

		events(app.window);
		onKeyPress();
		
		app.drawFrame();
        
        app.useFPS();
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
