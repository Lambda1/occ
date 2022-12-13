#ifndef OCC_VIRTUAL_SCREEN_H
#define OCC_VIRTUAL_SCREEN_H

#include <cstdint>

#include <vector>

namespace occ
{
	class VirtualScreen final
	{
		using SCRN_TYPE = uint32_t; // 画素値(RGBA)の型: Aは使わない

		// 色: シフト数
		// - enumでも良かったけど，キャストがだるいから変数にした
		inline static constexpr uint32_t RED   = 0u;
		inline static constexpr uint32_t GREEN = 8u;
		inline static constexpr uint32_t BLUE  = 16u;
		inline static constexpr uint32_t ALPHA = 24u;

		public:
		VirtualScreen(const uint32_t width, const uint32_t height, const uint8_t frameBufferNum);
		~VirtualScreen();

		// コンソール出力
		void Display() const;
		// コンソール出力を消す
		void Clear() const;
		// カーソルを初期位置に移動
		void Reset() const;

		// フレームバッファ選択
		void SelectFrameBuffer(const uint8_t index);
		// 画素値を設定
		void SetScreen(const uint32_t x, const uint32_t y, const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=0x00u);

		private:
		uint32_t CalcIndex_(const uint32_t x, const uint32_t y) const;

		SCRN_TYPE ConvertRGBA_(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=0x00u) const;

		private:
		const uint32_t m_screenWidth, m_screenHeight;
		const uint8_t m_frameBufferNum;

		uint8_t m_currentFrameBuffer;
		std::vector<SCRN_TYPE*> m_pScreens;
	};
}

#endif // OCC_VIRTUAL_SCREEN_H
