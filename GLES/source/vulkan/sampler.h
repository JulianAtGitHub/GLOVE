/**
 * Copyright (C) 2015-2018 Think Silicon S.A. (https://think-silicon.com/)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public v3
 * License as published by the Free Software Foundation;
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

/**
 *  @file       sampler.h
 *  @author     Think Silicon
 *  @date       25/07/2018
 *  @version    1.0
 *
 *  @brief      Texture Mapping Functionality via Image Samplers in Vulkan
 *
 */

#ifndef __VKSAMPLER_H__
#define __VKSAMPLER_H__

#include "context.h"

class CacheManager;

namespace vulkanAPI {

class Sampler {

private:
    const
    vkContext_t *                     mVkContext;

    VkSampler                         mVkSampler;
    VkFilter                          mVkMinFilter;
    VkFilter                          mVkMagFilter;
    VkSamplerMipmapMode               mVkMipmapMode;
    VkSamplerAddressMode              mVkAddressModeU;
    VkSamplerAddressMode              mVkAddressModeV;
    VkSamplerAddressMode              mVkAddressModeW;
    float                             mMinLod;
    float                             mMaxLod;
    float                             mMipLodBias;
    VkBool32                          mAnisotropyEnabled;
    float                             mMaxAnisotropy;
    VkBool32                          mCompareEnabled;
    VkCompareOp                       mVkCompareOp;
    VkBorderColor                     mVkBorderColor;
    VkBool32                          mUnnormalizedCoordinates;
    VkBool32                          mUpdated;

    uint64_t                          mHash;
    CacheManager *                    mCacheManager;

public:
// Constructor
    Sampler(const vkContext_t *vkContext = nullptr);

// Destructor
    ~Sampler();

// Create Functions
    bool                              Create(void);

// Release Functions
    void                              Release(void);

// Get Functions
    inline VkSampler                  GetSampler(void)                  const   { FUN_ENTRY(GL_LOG_TRACE); return mVkSampler; }

// Set Functions
    inline void                       SetContext(const vkContext_t *vkContext)  { FUN_ENTRY(GL_LOG_TRACE); mVkContext      = vkContext;                  }
    inline void                       SetCacheManager(CacheManager *manager)    { FUN_ENTRY(GL_LOG_TRACE); mCacheManager   = manager;                    }
    inline void                       SetMinFilter(VkFilter filter)             { FUN_ENTRY(GL_LOG_TRACE); if (mVkMinFilter     != filter)  { mVkMinFilter    = filter; mUpdated = VK_TRUE; } }
    inline void                       SetMagFilter(VkFilter filter)             { FUN_ENTRY(GL_LOG_TRACE); if (mVkMagFilter     != filter)  { mVkMagFilter    = filter; mUpdated = VK_TRUE; } }
    inline void                       SetAddressModeU(VkSamplerAddressMode mode){ FUN_ENTRY(GL_LOG_TRACE); if (mVkAddressModeU  != mode)    { mVkAddressModeU = mode;   mUpdated = VK_TRUE; } }
    inline void                       SetAddressModeV(VkSamplerAddressMode mode){ FUN_ENTRY(GL_LOG_TRACE); if (mVkAddressModeV  != mode)    { mVkAddressModeV = mode;   mUpdated = VK_TRUE; } }
    inline void                       SetAddressModeW(VkSamplerAddressMode mode){ FUN_ENTRY(GL_LOG_TRACE); if (mVkAddressModeW  != mode)    { mVkAddressModeW = mode;   mUpdated = VK_TRUE; } }
    inline void                       SetMipmapMode(VkSamplerMipmapMode mode)   { FUN_ENTRY(GL_LOG_TRACE); if (mVkMipmapMode    != mode)    { mVkMipmapMode   = mode;   mUpdated = VK_TRUE; } }
    inline void                       SetMaxLod(float lod)                      { FUN_ENTRY(GL_LOG_TRACE); if (mMaxLod          != lod)     { mMaxLod         = lod;    mUpdated = VK_TRUE; } }
};

}

#endif // __VKSAMPLER_H__
