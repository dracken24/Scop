/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyGestion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:03:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/08 12:04:13 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.hpp"
#include "../../includes/class/Scop.hpp"

extern Scop	scop;

void	resetTransform(void)
{
	scop._transform.translate.x = 0.0f;
	scop._transform.translate.y = 0.0f;
	scop._transform.translate.z = 0.0f;
	
	scop._transform.rotate.x = 0.0f;
	scop._transform.rotate.y = 0.0f;
	scop._transform.rotate.z = 0.0f;

	// Vector3 tmp = scop.getObjSize(scop._obj.at(scop._objIndex).objPath.c_str());
	
	scop._transform.scale.x = scop._far;
	scop._transform.scale.y = scop._far;
	scop._transform.scale.z = scop._far;
	scop._modifier.zoom = scop._far / 10;
}

void	onKeyPress(void)
{
	// Rotate //
	if (scop._keyCount.KEY_A == 1)
		scop._transform.rotate.x -= 2.0f;
	if (scop._keyCount.KEY_D == 1)
		scop._transform.rotate.x += 2.0f;
		
	if (scop._keyCount.KEY_W == 1)
		scop._transform.rotate.y -= 2.0f;
	if (scop._keyCount.KEY_S == 1)
		scop._transform.rotate.y += 2.0f;
		
	if (scop._keyCount.KEY_Q == 1)
		scop._transform.rotate.z -= 2.0f;
	if (scop._keyCount.KEY_E == 1)
		scop._transform.rotate.z += 2.0f;

	// Translate //
	if (scop._keyCount.KEY_UP == 1)
		scop._transform.translate.z += 0.025f;
	if (scop._keyCount.KEY_DOWN == 1)
		scop._transform.translate.z -= 0.025f;
		
	if (scop._keyCount.KEY_LEFT == 1)
	{
		scop._transform.translate.x += 0.025f;
		scop._transform.translate.y -= 0.025f;
	}
	if (scop._keyCount.KEY_RIGHT == 1)
	{
		scop._transform.translate.x -= 0.025f;
		scop._transform.translate.y += 0.025f;
	}

	// // Reset //
	// if (scop._space == 1)
	// 	resetTransform();
}

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// std::cout << "Key pressed: " << key << std::endl;
	
	switch (key)
	{
		// Rotate //	
		case GLFW_KEY_A:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_A = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_A = 0;
			break;
		case GLFW_KEY_D:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_D = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_D = 0;
			break;
			
		case GLFW_KEY_W:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_W = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_W = 0;
			break;
		case GLFW_KEY_S:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_S = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_S = 0;
			break;
			
		case GLFW_KEY_Q:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_Q = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_Q = 0;
			break;
		case GLFW_KEY_E:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_E = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_E = 0;
			break;
			
		// Translate //	
		case GLFW_KEY_UP:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_UP = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_UP = 0;
			break;
		case GLFW_KEY_DOWN:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_DOWN = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_DOWN = 0;
			break;
			
		case GLFW_KEY_LEFT:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_LEFT = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_LEFT = 0;
			break;
		case GLFW_KEY_RIGHT:
			if (action == GLFW_PRESS)
				scop._keyCount.KEY_RIGHT = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.KEY_RIGHT = 0;
			break;

		// case GLFW_KEY_1:
		// 	if (action == GLFW_PRESS)
		// 		scop._modeFil = VK_POLYGON_MODE_FILL;
		// 	break;
		// case GLFW_KEY_2:
		// 	if (action == GLFW_PRESS)
		// 		scop._modeFil = VK_POLYGON_MODE_LINE;
		// 	break;

		// Reset //
		case GLFW_KEY_SPACE:
			if (action == GLFW_PRESS)
			{
				// std::cout << "Reset" << std::endl;
				resetTransform();
			}
			break;

		// Exit //
		case GLFW_KEY_ESCAPE:
			if (action == GLFW_PRESS)
				scop._quit = false;
			break;
	}
}

void	mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	// std::cout << "Mouse button pressed: " << button << std::endl;
	// std::cout << "Mouse button action : " << action << std::endl;
	// std::cout << "Mouse button mods   : " << mods << std::endl;
	
	switch (button)
	{
		case GLFW_MOUSE_BUTTON_LEFT:
			if (action == GLFW_PRESS)
				scop._keyCount.MOUSE_LEFT = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.MOUSE_LEFT = 0;
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			if (action == GLFW_PRESS)
				scop._keyCount.MOUSE_RIGHT = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.MOUSE_RIGHT = 0;
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
			if (action == GLFW_MOUSE_BUTTON_MIDDLE)
				scop._keyCount.MOUSE_MIDDLE = 1;
			else if (action == GLFW_RELEASE)
				scop._keyCount.MOUSE_MIDDLE = 0;
			break;
	}
}

void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	// std::cout << "Scroll xoffset: " << xoffset << std::endl;
	// std::cout << "Scroll yoffset: " << yoffset << std::endl;

	if (yoffset == 1)
	{
		scop._transform.scale.x -= scop._modifier.zoom;
		scop._transform.scale.y -= scop._modifier.zoom;
		scop._transform.scale.z -= scop._modifier.zoom;
	}
	else if (yoffset == -1)
	{
		scop._transform.scale.x += scop._modifier.zoom;
		scop._transform.scale.y += scop._modifier.zoom;
		scop._transform.scale.z += scop._modifier.zoom;
	}
}

// Find position of the mouse on screen //
void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	// std::cout << "Cursor x: " << xpos << std::endl;
	// std::cout << "Cursor y: " << ypos << std::endl;
	
	scop._transform.mouse.x = static_cast<float>(xpos);
	scop._transform.mouse.y = static_cast<float>(ypos);
}


