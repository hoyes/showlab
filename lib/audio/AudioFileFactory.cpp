#include "AudioFileFactory.h"
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "SndFileAudioFile.h"

AudioFileRef AudioFileFactory::create(std::string filename)
{
    std::string ext = fs::extension(filename);
    AudioFileRef f;
    if (ext == ".wav" || ext == ".ogg" || ext == ".flac" || ext == ".aif" || ext == ".aiff" || ext == ".au") {
        f = AudioFileRef(new SndFileAudioFile);
    }
    f->open(filename);
    return f;
}
