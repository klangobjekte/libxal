/// @file
/// @author  Boris Mikic
/// @version 2.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php
/// 
/// @section DESCRIPTION
/// 
/// Represents a multi playlist.

#ifndef XAL_MULTI_PLAYLIST_H
#define XAL_MULTI_PLAYLIST_H

#include <hltypes/harray.h>

#include "xalUtilExport.h"

namespace xal
{
	class Playlist;

	class xalUtilExport MultiPlaylist
	{
	public:
		MultiPlaylist();
		~MultiPlaylist();
		
		bool isEnabled() { return this->enabled; }
		void setEnabled(bool value) { this->enabled = value; }
		harray<Playlist*> getPlaylists() { return this->playlists; }
		bool isPlaying();
		bool isPaused();

		void registerPlaylist(Playlist* playlist);
		void unregisterPlaylist(Playlist* playlist);

		void clear();
		
		void update();
		
		void play(float fadeTime = 0.0f);
		void stop(float fadeTime = 0.0f);
		void pause(float fadeTime = 0.0f);
		void shuffle();
		void reset();
		
	protected:
		bool enabled;
		harray<Playlist*> playlists;
	
	};
	
}

#endif
