/**
 * Copyright (c) 2018 Melown Technologies SE
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * *  Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef fb_hpp_included_
#define fb_hpp_included_

#include <memory>

#include "utility/gl.hpp"

#include "math/geometry_core.hpp"

namespace glsupport {

enum PixelType {
    rgb8, rgba8, rgb32f, rgba32f
};

class FrameBuffer {
public:
    /** Preferred version.
     */
    FrameBuffer(const math::Size2 &size
                , PixelType pixelType = PixelType::rgb8);

    /** Compatibility interface.
     */
    FrameBuffer(const math::Size2 &size, bool alpha);

    ~FrameBuffer();

private:
    void init();

    const math::Size2 size_;
    PixelType pixelType_;

    ::GLuint fbId_;
    ::GLuint depthTextureId_;
    ::GLuint colorTextureId_;
};

} // namespace glsupport

#endif // fb_hpp_included_
