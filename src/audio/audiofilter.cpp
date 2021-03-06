#include <fea/audio/audiofilter.hpp>
#include <fea/assert.hpp>
#include <utility>
#if !defined(FEA_NO_EFX)
#include "efx.h"
#endif

namespace fea
{
    AudioFilter::AudioFilter()
    {
#if !defined(FEA_NO_EFX)
        alGenFilters(1, &mFilterId);
#endif
    }

    AudioFilter::AudioFilter(AudioFilter&& other) : 
        mFilterId(0)
    {
        std::swap(mFilterId, other.mFilterId);
    }

    AudioFilter& AudioFilter::operator=(AudioFilter&& other)
    {
        std::swap(mFilterId, other.mFilterId);

        return *this;
    }

    AudioFilter::~AudioFilter()
    {
#if !defined(FEA_NO_EFX)
        if(mFilterId != 0)
            alDeleteFilters(1, &mFilterId);
#endif
    }
    
    ALuint AudioFilter::getFilterId() const
    {
        return mFilterId;
    }
}
