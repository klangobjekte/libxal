/// @file
/// @version 3.4
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Provides a source for OGG format.

#ifdef _FORMAT_OGG
#ifndef XAL_OGG_SOURCE_H
#define XAL_OGG_SOURCE_H

#include <vorbis/vorbisfile.h>

#include <hltypes/hstring.h>

#include "AudioManager.h"
#include "Source.h"
#include "xalExport.h"

namespace xal
{
	class xalExport OGG_Source : public Source
	{
	public:
		OGG_Source(chstr filename, SourceMode sourceMode, BufferMode bufferMode);
		~OGG_Source();

		bool open();
		void close();
		void rewind();
		bool load(hstream& output);
		int loadChunk(hstream& output, int size = STREAM_BUFFER_SIZE);

	protected:
		OggVorbis_File oggStream;

	};

}

#endif
#endif
