/*
  ==============================================================================

    Tracks.cpp
    Created: 9 Jun 2021 8:23:14pm
    Author:  matsm

    This file contains all definitions of the TrackManager and Track classes

    These classes are a very important part of the program, as they are 
    responsible for the majority of audio processing.

  ==============================================================================
*/

// Include header file, which contains all declarations of the TrackManager and Track classes
#include "Tracks.h"

TrackManager::TrackManager(string managerName) 
{

}

void TrackManager::createTrack(string trackName, Track::TrackType trackType)
{
    trackVector.push_back(Track(trackName, trackType));
}

Track::Track(string requestedName, TrackType requestedType) 
{
    trackName = requestedName;
    trackType = requestedType;
}

void Track::rename(string newName)
{
    trackName = newName;
}