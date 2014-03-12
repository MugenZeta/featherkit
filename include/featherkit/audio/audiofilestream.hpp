#pragma once
#include <featherkit/audio/audiostream.hpp>
#include <featherkit/audio/audiofile.hpp>

namespace fea
{
    class AudioFileStream : public AudioStream
    {
        public:
            AudioFileStream();
            virtual void fillBufferData(size_t sampleIndex, AudioData& toFill) override;
            void openFile(const std::string& path);
        private:
            AudioFile mFile;
    };
}
