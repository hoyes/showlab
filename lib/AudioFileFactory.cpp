#include "AudioFileFactory.h"
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

AudioFileRef AudioFileFactory::create(std::string filename)
{
    std::string ext = fs::extension(filename);
    AudioFileRef f;
    if (ext == ".wav") {
        f = AudioFileRef(new WavAudioFile);
    }
    f->open(filename);
    return f;
}
