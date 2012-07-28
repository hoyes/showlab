#include <iostream>
#include "lib/audio/AudioFileFactory.h"
#include "lib/audio/AudioManager.h"
#include "lib/Environment.h"
#include "thrift/ShowService_server.h"

int main(int argc, char* argv[]) {
	EnvironmentRef e(new Environment);

/*	AudioFileRef x = AudioFileFactory::create("finale.ogg");

	AudioFileRef y = AudioFileFactory::create("/home/peter/Shows/2011-05 Romeo and Juliet/edited/birdsong.wav");
	
	AudioFileRef z = AudioFileFactory::create("bell.wav");
	
	AudioMixerRef m = e->getAudioManager().getMixer(0);
	
	m->addFile(x);
    m->addFile(y);
	m->addFile(z);*/
	
	ShowLabServer s(e);
	s.start();	
}
