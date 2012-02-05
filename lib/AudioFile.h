#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <string>
#include <vector>
#include <boost/circular_buffer.hpp>
#include <memory>

typedef std::shared_ptr<std::vector<float>> SampleList;

class AudioFile {
	
public:
        AudioFile();
        virtual ~AudioFile();
        void open(std::string fileName);
        
	std::string FileName() { return mFileName; }
	int Frames() { return mFrames; }
	int Position() { return mPosition; }
	int Channels() { return mChannels; }
	int SampleRate() { return mSampleRate; }
	float Length() { return mFrames / mSampleRate; }

	void load();
	void unload();
	virtual void fillBuffer() = 0;
	SampleList getSamples(int number);
	void clearSamples(int number);
	
	

protected:
	virtual void doLoad() = 0;
	virtual void doUnload() = 0;
	
	void Frames(int v) { mFrames = v; }
	void Channels(int v) { mChannels = v; }
	void SampleRate(int v) { mSampleRate = v; }
	
        boost::circular_buffer<float> buffer;

private:
	std::string mFileName;
	int mFrames;
	int mPosition;
	int mChannels;
	int mSampleRate;

	bool loaded;

};

typedef std::shared_ptr<AudioFile> AudioFileRef;

#endif
