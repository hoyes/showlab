#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <string>
#include <vector>
#include <boost/circular_buffer.hpp>
#include <memory>

class AudioFile;
typedef std::shared_ptr<std::vector<float>> SampleList;
typedef std::shared_ptr<AudioFile> AudioFileRef;

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
	virtual void addToBuffer(SampleList samples, unsigned int num) = 0;
	SampleList getSamples(int number);
	void clearSamples(int number);
	
	static AudioFileRef create(std::string filename);

protected:
	virtual void doLoad() = 0;
	virtual void doUnload() = 0;
	
	void Frames(int v) { mFrames = v; }
	void Channels(int v) { mChannels = v; }
	void SampleRate(int v) { mSampleRate = v; }
	
private:
	std::string mFileName;
	int mFrames;
	int mPosition;
	int mChannels;
	int mSampleRate;

	bool loaded;

};

#endif
