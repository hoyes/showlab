#include <iostream>
#include "lib/WavAudioFile.h"
#include "lib/AudioManager.h"
#include "lib/Environment.h"
#include "thrift/ShowService_server.h"

int main(int argc, char* argv[]) {
	AudioFileRef x(new WavAudioFile);
	x->open("/home/peter/Shows/2011-05 Romeo and Juliet/edited/liebestod instruemtnal.wav");

	AudioFileRef y(new WavAudioFile);
	y->open("/home/peter/Shows/2011-05 Romeo and Juliet/edited/birdsong.wav");
	
	AudioFileRef z(new WavAudioFile);
	z->open("bell.wav");
	
	AudioManager man;
	AudioMixerRef m = man.addMixer("default");
	
	m->addFile(x);
    m->addFile(y);
	m->addFile(z);
	
	std::shared_ptr<Environment> e(new Environment);
	
	ShowLabServer s(e);
	s.start();	
}
