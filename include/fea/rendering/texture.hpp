#pragma once
#include <fea/config.hpp>
#include <stdint.h>
#include <fea/rendering/opengl.hpp>
#include <fea/rendering/color.hpp>
#include <glm/glm.hpp>
#include <functional>
#include <memory>

namespace fea
{
    class FEA_API Texture
    {
        public:
            Texture();
            Texture(const Texture& other) = delete;
            Texture& operator=(const Texture& other) = delete;
            Texture(Texture&& other);
            Texture& operator=(Texture&& other);
            GLuint getId() const;
            void create(uint32_t width, uint32_t height, const uint8_t* imageData, bool smooth = false, bool interactive = false);
            void create(uint32_t width, uint32_t height, const Color& color, bool smooth = false, bool interactive = false);
            glm::uvec2 getSize() const;
            void destroy();
            void setPixel(uint32_t x, uint32_t y, const Color& color);
            Color getPixel(uint32_t x, uint32_t y) const;
            uint8_t* getPixelData();
            const uint8_t* getPixelData() const;
            void update();
            ~Texture();
        private:
            GLuint mId;
            uint32_t mWidth;
            uint32_t mHeight;
            bool mInteractive;
            std::unique_ptr<uint8_t[]> pixelData;
    };
    /** @addtogroup Rendering
     *@{
     *  @class Texture
     *@}
     ***
     *  @class Texture
     *  @brief Container class for a texture resource that can be used by Drawable2D instances.
     *
     *  To use a texture, it needs to be created using the create function. Because Textures represents internal textures of the rendering system, they cannot be copied. Textures can optionally be created as interactive. In that case, pixels can be accessed and updated at any time.
     *
     *  A Texture instance has to be kept alive as long as there are drawables using it, otherwise they will be rendered with an invalid Texture.
     ***
     *  @fn Texture::Texture()
     *  @brief Construct an uninitialized Texture.
     ***
     *  @fn Texture::Texture(Texture&& other)
     *  @brief Move constructor.
     *  @param other Other instance.
     ***
     *  @fn Texture::Texture(const Texture& other) = delete
     *  @brief Deleted copy constructor.
     *  @param other Instance to copy.
     ***
     *  @fn Texture& Texture::operator=(Texture&& other)
     *  @brief Move assignment operator.
     *  @param other Other instance.
     ***
     *  @fn Texture& Texture::operator=(const Texture& other)
     *  @brief Deleted assignment operator.
     *  @param other Other instance.
     ***
     *  @fn int32_t Texture::getId() const
     *  @brief Get the ID of the internal texture.
     ***
     *  @fn void Texture::create(uint32_t width, uint32_t height, const uint8_t* imageData, bool smooth = false, bool interactive = false)
     *  @brief Create a texture from an image.
     *  
     *  When the texture is successfully created, it can be used by drawables. Keep in mind that the texture must be kept alive as long as it is in use by any drawable. If the texture is created in interactive mode, it can be used to access and updated pixels at any time.
     *  Assert/undefined behavior when width or height is zero or less.
     *
     *  @param width Width of the texture in pixels.
     *  @param height Height of the texture in pixels.
     *  @param imageData Image to create the texture from. Must be in 32-bit RGBA format.
     *  @param smooth If this is true, the texture will be smoothed using nearest neighbor interpolation.
     *  @param interactive If this is true, pixels can be accessed and updated using the setPixel and getPixel methods.
     ***
     *  @fn void Texture::create(uint32_t width, uint32_t height, const Color& color, bool smooth = false, bool interactive = false)
     *  @brief Create a texture filled with a color.
     *  
     *  When the texture is successfully created, it can be used by drawables. Keep in mind that the texture must be kept alive as long as it is in use by any drawable. If the texture is created in interactive mode, it can be used to access and updated pixels at any time.
     *  Assert/undefined behavior when width or height is zero or less.
     *
     *  @param width Width of the texture in pixels.
     *  @param height Height of the texture in pixels.
     *  @param color Color to fill the texture with.
     *  @param smooth If this is true, the texture will be smoothed using nearest neighbor interpolation.
     *  @param interactive If this is true, pixels can be accessed and updated using the setPixel and getPixel methods.
     ***
     *  @fn glm::uvec2 Texture::getSize() const
     *  @brief Return the size of the texture.
     *  @return Texture size.
     ***
     *  @fn void Texture::destroy()
     *  @brief Release the resources used by the texture. The texture will be invalid afterwards.
     ***
     *  @fn void Texture::setPixel(uint32_t x, uint32_t y, const Color& color)
     *  @brief Set the color of a particular pixel.
     *
     *  Setting a pixel using this method does not change the Texture until the Texture::update method has been called. This method requires the texture to be set to interactive.
     *  Assert/undefined behavior when setting a pixel outside of the dimensions of the texture.
     *  @param x X index of the pixel.
     *  @param y Y index of the pixel.
     *  @param color Color to set the pixel to.
     ***
     *  @fn Color Texture::getPixel(uint32_t x, uint32_t y) const
     *  @brief Access the color value of a pixel.
     *
     *  This method requires the texture to be set to interactive.
     *  Assert/undefined behavior when getting a pixel outside of the dimensions of the texture.
     *
     *  @return The color value of the pixel.
     ***
     *  @fn uint8_t* Texture::getPixelData()
     *  @brief Get internal pixel data.
     *
     *  Accessing the internal data can be important for intense manipulation of many pixels where performance is crucial. To be used with caution.
     *  Undefined behavior when data outside the texture dimensions are accessed.
     *  @return Data.
     ***
     *  @fn const uint8_t* Texture::getPixelData() const
     *  @brief Get internal pixel data.
     *
     *  Accessing the internal data can be important for intense accessing of pixels. To be used with caution.
     *  Undefined behavior when data outside the texture dimensions are accessed.
     *  @return Data.
     ***
     *  @fn void Texture::update()
     *  @brief Update the texture with any changes made using any of the Texture::setPixel methods.
     *
     *  Assert/undefined behavior when this is called an a non-interactive texture.
     *  This method requires the texture to be set to interactive.
     ***
     *  @fn Texture::~Texture()
     *  @brief Destruct a texture.
     **/
}
