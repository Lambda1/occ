#include "VirtualScreen.h"

#include <cstdlib>
#include <cassert>

#include <iostream>
#include <string>
#include <sstream>

namespace occ
{
	VirtualScreen::VirtualScreen(const uint32_t width, const uint32_t height, const uint8_t frameBufferNum):
		m_screenWidth(width), m_screenHeight(height), m_frameBufferNum(frameBufferNum),
		m_currentFrameBuffer(0u), m_pScreens(frameBufferNum, NULL)
	{
		const uint32_t buffSize = m_screenWidth * m_screenHeight;
		for (auto itr : m_pScreens)
		{
			itr = new SCRN_TYPE[buffSize];
			assert(itr != NULL);
			for (uint32_t j = 0u; j < buffSize; ++j) { itr[j] = 0u; }
		}
	}

	VirtualScreen::~VirtualScreen()
	{
		for (auto itr : m_pScreens)
		{ delete[] itr; }
	}

	void VirtualScreen::Display() const
	{
	}

	void VirtualScreen::Clear() const
	{
	}

	void VirtualScreen::Reset() const
	{
	}

	void VirtualScreen::SelectFrameBuffer(const uint8_t index)
	{
		if (index >= m_frameBufferNum)
		{
			std::cerr << "ERROR: index is out of range." << std::endl;
			std::exit(1);
		}
		m_currentFrameBuffer = index;
	}

	void VirtualScreen::SetScreen(const uint32_t x, const uint32_t y, const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
	{
		const uint32_t index = CalcIndex_(x, y);
		const uint32_t val = ConvertRGBA_(r, g, b, a);
		m_pScreens[m_currentFrameBuffer][index] = val;
	}

	uint32_t VirtualScreen::CalcIndex_(const uint32_t x, const uint32_t y) const
	{
		const uint32_t index = y * m_screenWidth + x;
		if (index >= m_screenWidth*m_screenHeight)
		{
			std::cerr << "ERROR: index is out of range." << std::endl;
			std::exit(1);
		}
		return index;
	}

	VirtualScreen::SCRN_TYPE VirtualScreen::ConvertRGBA_(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a) const
	{
		const uint32_t red   = (static_cast<SCRN_TYPE>(r) << RED)   & (static_cast<SCRN_TYPE>(0xffu) << RED);
		const uint32_t green = (static_cast<SCRN_TYPE>(g) << GREEN) & (static_cast<SCRN_TYPE>(0xffu) << GREEN);
		const uint32_t blue  = (static_cast<SCRN_TYPE>(b) << BLUE)  & (static_cast<SCRN_TYPE>(0xffu) << BLUE);
		const uint32_t alpha = (static_cast<SCRN_TYPE>(a) << ALPHA) & (static_cast<SCRN_TYPE>(0xffu) << ALPHA);
		return (red | green | blue | alpha);
	}
}
