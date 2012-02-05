import sys,os

env = Environment()

sources = Glob("*.cpp")
sources.extend(Glob("lib/*.cpp"))
sources.extend(Glob("thrift/*.cpp"))
object_list = env.Object(source = sources)


conf = Configure(env)
#if conf.CheckCHeader('wx-2.8/wx/wx.h'):
#    env.Append(CPPPATH = ['/usr/include/wx-2.8/'])
env.Append(LIBS = ['portaudio'])

env.Program(target='showlab', source=object_list)
#env.ParseConfig('wx-config --cxxflags --libs')
env.ParseConfig('pkg-config --cflags --libs sndfile samplerate thrift')
env.Append(CCFLAGS = ['-Wall','-std=c++0x', '-g', '-DHAVE_INTTYPES_H', '-DHAVE_NETINET_IN_H'])


sources = Glob("client/*.cpp")
sources.extend(Glob("thrift/*.cpp"))
object_list = env.Object(source = sources)
env.Program(target='showlab-client', source=object_list)
