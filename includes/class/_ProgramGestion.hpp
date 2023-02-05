/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ProgramGestion.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:53:06 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/05 15:51:56 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PROGRAMGESTION_HPP
# define _PROGRAMGESTION_HPP

#if _WIN32
	#define GLFW_EXPOSE_NATIVE_WIN32
	#define VK_USE_PLATFORM_WIN32_KHR
#endif
#if __APPLE__
	#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#if __linux__
	#define GLFW_EXPOSE_NATIVE_X11
#endif

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include "../color.hpp"
// #include "../engine.hpp"

#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <optional>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <limits>
#include <chrono>
#include <set>
#include <map>
#include <chrono>
#include <thread>

#include <unordered_map>

#define WIDTH 1500
#define HEIGHT 920

// Validation layers //
const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

// Device extensions //
const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

// Vertex data //


// const std::vector<uint16_t> indices = {
//     0, 1, 2, 2, 3, 0,
// 	4, 5, 6, 6, 7, 4
// };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

//******************************************************************************************************//

const int MAX_FRAMES_IN_FLIGHT = 2; // Max number of frames that can be in flight at the same time

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	static VkVertexInputBindingDescription getBindingDescription()
	{
		VkVertexInputBindingDescription bindingDescription{};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

		return bindingDescription;
	}

	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions()
	{
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};

		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}

	bool operator==(const Vertex& other) const
	{
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

namespace std
{
	template<> struct hash<Vertex>
	{
		size_t operator()(Vertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos) ^
				(hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^
				(hash<glm::vec2>()(vertex.texCoord) << 1);
		}
	};
}

// Uniform buffer object or UBO//
struct UniformBufferObject
{
	// alignas(16)glm::vec2 foo;
	alignas(16)glm::mat4 model;
	alignas(16)glm::mat4 view;
	alignas(16)glm::mat4 proj;
};

typedef struct  Vector3
{
	float	x;
	float	y;
	float	z;
}               Vector3;

typedef struct  Vector2
{
	float	x;
	float	y;
}               Vector2;

typedef struct  Texture2D
{
	std::string		imgPath;
	std::string		imgName;
	Vector2			imgSize;

	std::string		imgType;
}               Texture2D;

typedef struct  Obj
{
	std::string		objPath;
	std::string		objName;
}               Obj;

typedef struct		Rotate
{
	Vector3        axis;
	float          angle;
}					Rotate;

//******************************************************************************************************//

class ProgramGestion
{
	//******************************************************************************************************//
	//												Structs										    		//
	//******************************************************************************************************//
	public:

		// Queue family indices //
		struct QueueFamilyIndices
		{
			std::optional<uint32_t>		graphicsFamily;
			std::optional<uint32_t>		presentFamily;
			
			bool isComplete()
			{
				return graphicsFamily.has_value() && presentFamily.has_value();
			}
		};

		// Swap chain support details //
		struct SwapChainSupportDetails
		{
			VkSurfaceCapabilitiesKHR capabilities;
			std::vector<VkSurfaceFormatKHR> formats;
			std::vector<VkPresentModeKHR> presentModes;
		};

		// Uniform buffer square object contnant 2 triangles //
		std::vector<Vertex> vertices;

	//******************************************************************************************************//
	//												Functions									    		//
	//******************************************************************************************************//

	//******************************************************************************************************//
	//										Constructor - Destructor							    		//
	//******************************************************************************************************//

	public:
		ProgramGestion();
		ProgramGestion(const ProgramGestion &src);
		~ProgramGestion();
		
		ProgramGestion	&operator=(const ProgramGestion &src);
	
	//******************************************************************************************************//
	//											Public Methods									    		//
	//******************************************************************************************************//

	// Public Methods //
	public:
		void		init(std::string name);
		void		drawFrame();
		void		useFPS(void);
		void		setFPS(int fps);
	
		void		cleanup();

	// Draw //
		void		putPixel(int x, int y, int color);

	// Setters//
		void		setDeltaTime(float deltaTime, int flag);

	// Getters//
		float			getDeltaTime() const;

	// Others //
		Vector2		getImgSize(const char *path);

	// Init //
		void		initVariables(int argc, char **argv);

	//******************************************************************************************************//
	//											Private Methods									    		//
	//******************************************************************************************************//

	private:
		void	initWindow(std::string name);
		void	initVulkan();
		void	mainLoop();
		// void	cleanup();

	//******************************************************************************************************//
	//													GPU										    		//
	//******************************************************************************************************//

		void	createLogicalDevice();
		void	pickPhysicalDevice(); //- Find Graphic card -//
		int 	chooseGPU(std::multimap<int, VkPhysicalDevice> devices);
		
		bool	checkDeviceExtensionSupport(VkPhysicalDevice device);
		bool	isDeviceSuitable(VkPhysicalDevice device);

		int		rateDeviceSuitability(VkPhysicalDevice device);

	//******************************************************************************************************//
	//												Queue										    		//
	//******************************************************************************************************//

		VkPresentModeKHR			chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkSurfaceFormatKHR 			chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkExtent2D					chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		SwapChainSupportDetails		querySwapChainSupport(VkPhysicalDevice device);
		QueueFamilyIndices			findQueueFamilies(VkPhysicalDevice device);
		
		void	recreateSwapChain();
		void	createSwapChain();
		void	cleanupSwapChain();
		
		void	createImageViews();

	//******************************************************************************************************//
	//												Surface										    		//
	//******************************************************************************************************//
	
		void	createSurface();

	//******************************************************************************************************//
	//									Instance creation and debug messages						    	//
	//******************************************************************************************************//

		void	createInstance();
		bool	checkValidationLayerSupport();
		void	setupDebugMessenger();

		std::vector<const char*>	getRequiredExtensions();

		void		DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
						const VkAllocationCallbacks* pAllocator);
		
		VkResult	CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT
						*pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
		
		void		populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	
	//******************************************************************************************************//
	//											Pipeline functions								    		//
	//******************************************************************************************************//

		VkShaderModule	createShaderModule(const std::vector<char> &code);
		void			createGraphicsPipeline();
		void			createRenderPass();
		void			createFramebuffers();

	//******************************************************************************************************//
	//										Command pool and buffer								    		//
	//******************************************************************************************************//

		void	recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
		void	createCommandBuffers();
		void	createCommandPool();

		void	createSyncObjects();

		// Callback //
		static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
		{
			auto app = reinterpret_cast<ProgramGestion*>(glfwGetWindowUserPointer(window));
    		app->framebufferResized = true;
		}
	
	//******************************************************************************************************//
	//											Vertex buffer									    		//
	//******************************************************************************************************//

		void		createVertexBuffer();
		uint32_t	findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
		void		copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
		void		createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties,
						VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		
	//******************************************************************************************************//
	//											Index buffer								    		//
	//******************************************************************************************************//
	// Index buffer //
		void		createIndexBuffer();

	// Uniform buffer //
		void		updateUniformBuffer(uint32_t currentImage);
		void		createDescriptorSetLayout();
		void		createUniformBuffers();
		void		createDescriptorPool();
		void		createDescriptorSets();
		
	//******************************************************************************************************//
	//											Texture mapping									    		//
	//******************************************************************************************************//

		void			createImage(uint32_t width, uint32_t height, uint32_t mipLevels,
							VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling,
								VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image,
									VkDeviceMemory& imageMemory);
		void			transitionImageLayout(VkImage image, VkFormat format,
							VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
		void			copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
		void			createTextureImage(Texture2D texture);
		void			endSingleTimeCommands(VkCommandBuffer commandBuffer);
		VkCommandBuffer	beginSingleTimeCommands();

		void			createTextureImageView();
		VkImageView		createImageView(VkImage image, VkFormat format,
							VkImageAspectFlags aspectFlags, uint32_t mipLevels);
		void			createTextureSampler();

	//******************************************************************************************************//
	//											Depth buffer									    		//
	//******************************************************************************************************//

		void		createDepthResources();
		VkFormat	findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling,
						VkFormatFeatureFlags features);
		VkFormat	findDepthFormat();
		bool		hasStencilComponent(VkFormat format);
		
	//******************************************************************************************************//
	//												Model										    		//
	//******************************************************************************************************//

		void		loadModel();

	//******************************************************************************************************//
	//												Minimaps									    		//
	//******************************************************************************************************//
	
		void		generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
						int32_t texHeight, uint32_t mipLevels);

	//******************************************************************************************************//
	//											Multisampling									    		//
	//******************************************************************************************************//

		VkSampleCountFlagBits	getMaxUsableSampleCount();
		void					createColorResources();
		
	//******************************************************************************************************//
	//												Others										    		//
	//******************************************************************************************************//

		std::vector<char>	readFile(const std::string &filename);
		float				deltaTime(void);

	public:
		void 	changeTexture(Texture2D	texture);
		void	chooseTexture();
		void	changeMesh(Obj mesh);
	
	//******************************************************************************************************//
	//												Variables									    		//
	//******************************************************************************************************//

	// Public Attributes //
	public:
		bool							_quit = true;	
		float							_FPS = 60;
		float							_zoom = 45.0f;
		Vector3							_translate = {0.0f, 0.0f, 0.0f};
		Vector3							_scale = {1.0f, 1.0f, 1.0f};
		Vector2							_mousePos = {0.0f, 0.0f};

		GLFWwindow						*window;	//- Stock window -//
		
		Vector3							_rotate = {0.0f, 0.0f, 0.0f};
		uint							_w = 0;
		uint							_a = 0;
		uint							_s = 0;
		uint							_d = 0;
		uint							_e = 0;
		uint							_q = 0;
		
		uint							_up = 0;
		uint							_down = 0;
		uint							_left = 0;
		uint							_right = 0;

		uint							_mouseLeft = 0;
		uint							_mouseRight = 0;
		uint							_mouseMiddle = 0;
		
		uint							_space = 0;

		Texture2D						_defaultTexture;

		std::string MODEL_PATH;
		// std::string TEXTURE_PATH;

		// std::string MODEL_PATH_DROP;
		// std::string TEXTURE_PATH_DROP;

		std::vector<Texture2D>	_textures;
		std::vector<Obj> 		_obj;
		bool					_texture = false;
		int						_textureIndex = 0;
		bool					_thread = true;
	
	// Private Attributes //
	private:
		VkInstance						instance;	//- Stock instance -//
		uint							widith = WIDTH;
		uint							height = HEIGHT;	
		
		VkDebugUtilsMessengerEXT		debugMessenger;	//- Debug messenger -//
		
		VkPhysicalDevice				physicalDevice = VK_NULL_HANDLE; //- Stock graphic card -//	
		VkSurfaceKHR					surface; 				//- Stock surface -//
		VkDevice						device; 				//- Stock logical device -//
		
		VkQueue							graphicsQueue;			//- Stock queue -//
		VkQueue							presentQueue;			//- Stock queue -//

		std::vector<VkImageView>		swapChainImageViews;	//- Stock swap chain image views -//
		std::vector<VkImage> 			swapChainImages;		//- Stock swap chain images -//
		VkSwapchainKHR					swapChain;				//- Stock swap chain -//
		VkExtent2D						swapChainExtent; 		//- Stock swap chain extent -//
		VkFormat						swapChainImageFormat;	//- Stock swap chain image format -//
		
		VkRenderPass 					renderPass;				//- Stock render pass -//
		VkDescriptorSetLayout			descriptorSetLayout;	//- Stock descriptor set layout -//
		VkPipelineLayout				pipelineLayout;			//- Stock pipeline layout -//
		VkPipeline						graphicsPipeline;		//- Stock graphics pipeline -//
		std::vector<VkFramebuffer>		swapChainFramebuffers;	//- Stock swap chain framebuffers -//

	// Command buffers //
		VkCommandPool					commandPool;			//- Stock command pool -//
		std::vector<VkCommandBuffer>	commandBuffers;			//- Stock command buffer -//

	// Stocking semaphores //
		std::vector<VkSemaphore>		imageAvailableSemaphores;	//- Stock image available semaphore -//
		std::vector<VkSemaphore>		renderFinishedSemaphores;	//- Stock render finished semaphore -//
		std::vector<VkFence>			inFlightFences;				//- Stock in flight fence -//
		
		bool							framebufferResized = false;	//- Stock framebuffer resized -//
		uint32_t						currentFrame = 0;			//- Stock current frame -//
		
		VkBuffer						vertexBuffer;				//- Stock vertex buffer -//
		VkDeviceMemory					vertexBufferMemory;			//- Stock vertex buffer memory -//
		VkBuffer						indexBuffer;				//- Stock index buffer -//
		VkDeviceMemory					indexBufferMemory;			//- Stock index buffer memory -//

		std::vector<VkBuffer>			uniformBuffers;				//- Stock uniform buffer -//
		std::vector<VkDeviceMemory>		uniformBuffersMemory;		//- Stock uniform buffer memory -//
		std::vector<void*>				uniformBuffersMapped;		//- Stock uniform buffer mapped -//
		VkDescriptorPool				descriptorPool;				//- Stock descriptor pool -//
		std::vector<VkDescriptorSet>	descriptorSets;				//- Stock descriptor set -//

	// Texture mapping //
		uint32_t						mipLevels;					//- Stock minimap levels -//
		VkImage							textureImage;				//- Stock texture image -//
		VkDeviceMemory					textureImageMemory;			//- Stock texture image memory -//
		VkImageView						textureImageView;			//- Stock texture image view -//
		VkSampler						textureSampler;				//- Stock texture sampler -//
		
		VkImage							depthImage;					//- Stock depth image -//
		VkDeviceMemory					depthImageMemory;			//- Stock depth image memory -//
		VkImageView						depthImageView;				//- Stock depth image view -//

		std::vector<uint32_t>			indices;					//- Stock indices -//
		
	// Multisampling //
		VkSampleCountFlagBits			msaaSamples = VK_SAMPLE_COUNT_1_BIT;	//- Stock multisampling -//
		VkImage 						colorImage;					//- Stock color image -//
		VkDeviceMemory					colorImageMemory;			//- Stock color image memory -//
		VkImageView						colorImageView;				//- Stock color image view -//
		
		float							_deltaTime = 0.0f;
};

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void	mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void	cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void	drop_callback(GLFWwindow* window, int count, const char** paths);
void	resetTransform(void);
void	onKeyPress(void);

int		events(GLFWwindow *window);

#endif
