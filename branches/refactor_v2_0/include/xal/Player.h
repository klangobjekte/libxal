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
/// Provides an interface to play and control audio data.

#ifndef XAL_PLAYER_H
#define XAL_PLAYER_H

#include "xalExport.h"

namespace xal
{
	class Buffer;
	class Sound;

	class xalExport Player
	{
	public:
		Player(Sound* sound, Buffer* buffer);
		virtual ~Player();

		float getGain() { return this->gain; }
		virtual void setGain(float value);
		float getOffset() { return this->offset; }
		Sound* getSound() { return this->sound; }
		hstr getName();
		float getDuration();

		Category* getCategory();

		virtual bool isPlaying() { return false; }
		bool isPaused();
		bool isFading();
		bool isFadingIn();
		bool isFadingOut();
		bool isLooping() { return this->looping; }

		virtual void update(float k);
		
		void play(float fadeTime = 0.0f, bool looping = false);
		void stop(float fadeTime = 0.0f);
		void pause(float fadeTime = 0.0f);

	protected:
		float gain;
		bool paused;
		bool looping;
		float fadeSpeed;
		float fadeTime;
		float offset; // TODO - should be int?
		Sound* sound;
		Buffer* buffer;

		float _calcGain();
		float _calcFadeGain();
		void _stopSound(float fadeTime = 0.0f);

		virtual float _sysGetOffset() { return 1.0f; }
		virtual void _sysSetOffset(float value) { }
		virtual bool _sysPreparePlay() { return true; }
		virtual void _sysPrepareBuffer(int channels, int rate, unsigned char* stream, int size) { }
		virtual void _sysUpdateFadeGain() { }
		virtual void _sysPlay() { }
		virtual void _sysStop() { }

	};

}
#endif
