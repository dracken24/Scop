/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 04:35:16 by nadesjar          #+#    #+#             */
/*   Updated: 2023/02/08 04:40:27 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_HPP
# define SCOP_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <GLFW/glfw3.h>

#define WIDTH 1500
#define HEIGHT 920

class Scop
{
    public:
        Scop();
        ~Scop();
        Scop(Scop const &src);
        Scop	&operator=(Scop const &rhs);

        void    mainLoop();
        static void    framebufferResizeCallback(GLFWwindow *window, int width, int height);
        int     main(void);

    public:
        GLFWwindow	*window;
        bool framebufferResized = false; //- Stock framebuffer resized -//

    private:
        
};

#endif
