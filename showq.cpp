#include "lib/WavAudioFile.h"
#include "lib/AudioManager.h"
#include <iostream>

int main(int argc, char* argv[]) {
	AudioFileRef x(new WavAudioFile);
	x->open("/home/peter/Shows/2011-05 Romeo and Juliet/edited/liebestod instruemtnal.wav");

	AudioFileRef y(new WavAudioFile);
	y->open("/home/peter/Shows/2011-05 Romeo and Juliet/edited/birdsong.wav");
	
	AudioFileRef z(new WavAudioFile);
	z->open("/home/peter/Shows/2011-05 Romeo and Juliet/edited/bell.wav");
	
	AudioManager man;
	AudioMixerRef m = man.addMixer("default");
	
	m->addFile(x);
	m->addFile(y);
	m->addFile(z);
	
	sleep(90);
	
}
