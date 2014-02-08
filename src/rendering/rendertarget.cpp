#include <featherkit/rendering/rendertarget.h>

namespace fea
{
    RenderTarget::RenderTarget() : mId(0), mWidth(0), mHeight(0)
    {
    }

    RenderTarget::RenderTarget(RenderTarget&& other) : mId(0), mWidth(0), mHeight(0)
    {
        std::swap(mId, other.mId);
        std::swap(mWidth, other.mWidth);
        std::swap(mHeight, other.mHeight);
        std::swap(mTexture, other.mTexture);
    }

    RenderTarget& RenderTarget::operator=(RenderTarget&& other)
    {
        std::swap(mId, other.mId);
        std::swap(mWidth, other.mWidth);
        std::swap(mHeight, other.mHeight);
        std::swap(mTexture, other.mTexture);

        return *this;
    }

    GLuint RenderTarget::getId() const
    {
        return mId;
    }

    glm::uvec2 RenderTarget::getSize() const
    {
        return glm::uvec2(mWidth, mHeight);
    }
    
    const Texture& RenderTarget::getTexture() const
    {
        return mTexture;
    }

    void RenderTarget::create(uint32_t w, uint32_t h, bool smooth)
    {
        if(mId)
        {
            destroy();
        }

        GLuint textureId;

        glGenFramebuffers(1, &mId);
        glBindFramebuffer(GL_FRAMEBUFFER, mId);

        mTexture.create(w, h, nullptr);
    
        glBindTexture(GL_TEXTURE_2D, mTexture.getId());
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mTexture.getId(), 0);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void RenderTarget::destroy()
    {
        if(mId)
        {
            mTexture.destroy();
            glDeleteFramebuffers(1, &mId);
            mId = 0;
        }
    }

    RenderTarget::~RenderTarget()
    {
        if(mId)
        {
            destroy();
        }
    }
}
