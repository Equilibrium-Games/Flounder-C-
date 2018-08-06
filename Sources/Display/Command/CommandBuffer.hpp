#pragma once

#include <vulkan/vulkan.h>
#include "Engine/Exports.hpp"

namespace acid
{
	class ACID_EXPORT CommandBuffer
	{
	private:
		VkQueueFlagBits m_queueType;
		VkCommandBufferLevel m_bufferLevel;
		VkCommandBuffer m_commandBuffer;
	public:
		CommandBuffer(const bool &begin = true, const VkQueueFlagBits &queueType = VK_QUEUE_GRAPHICS_BIT, const VkCommandBufferLevel &bufferLevel = VK_COMMAND_BUFFER_LEVEL_PRIMARY);

		~CommandBuffer();

		void Begin(const VkCommandBufferUsageFlags &usage = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT) const;

		void End() const;

		void Submit(const bool &waitFence = true, const VkSemaphore &semaphore = VK_NULL_HANDLE) const;

		VkCommandBuffer GetCommandBuffer() const { return m_commandBuffer; }
	private:
		VkQueue GetQueue() const;
	};
}
