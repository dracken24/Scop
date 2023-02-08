/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:13:00 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 08:55:54 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include <GLFW/glfw3.h>

#include "../includes/class/Scop.hpp"

Scop	scop;

void    mainLoop()
{
	while (glfwWindowShouldClose(scop.window) != true)
	{
		glfwPollEvents();

		// events(window);
		
		// drawFrame();
		
		// useFPS();	// Wait for 16.666 ms to have 60 fps //

		// std::cout << "FPS: " << i << std::endl;
		// i++;
	}
}

// Callback //
static void framebufferResizeCallback(GLFWwindow *window, int width, int height)
{
	auto app = reinterpret_cast<Scop *>(glfwGetWindowUserPointer(window));
	scop.framebufferResized = true;
}

int     main(void)
{
	std::cout << scop.ff << std::endl;

	try
	{
		// app.initVariables(argc, argv);
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		scop.window = glfwCreateWindow(WIDTH, HEIGHT, "BANKAI", nullptr, nullptr);

		glfwSetWindowUserPointer(scop.window, nullptr);
		glfwSetFramebufferSizeCallback(scop.window, framebufferResizeCallback);

		mainLoop();

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// else
	// {
	// 	std::cout << RED << "Usage: ./scop [file.obj] [texture file.png or .jpg or ...]" << RESET << std::endl;
	// 	return EXIT_FAILURE;
	// }

	return EXIT_SUCCESS;
}
