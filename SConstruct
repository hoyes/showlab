import sys,os

env = Environment()

sources = Glob("*.cpp")
sources.extend(Glob("lib/*.cpp"))
object_list = env.Object(source = sources)


conf = Configure(env)
#if conf.CheckCHeader('wx-2.8/wx/wx.h'):
#    env.Append(CPPPATH = ['/usr/include/wx-2.8/'])
env.Append(LIBS = ['portaudio'])

env.Program(target='ShowQ', source=object_list)
#env.ParseConfig('wx-config --cxxflags --libs')
env.ParseConfig('pkg-config --cflags --libs sndfile samplerate')
env.Append(CCFLAGS = ['-Wall','-std=c++0x', '-g'])
