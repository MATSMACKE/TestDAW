/*
  ==============================================================================

    Tracks.h
    Created: 9 Jun 2021 8:23:14pm
    Author:  matsm

    This file contains all declarations of the TrackManager and Track classes

  ==============================================================================
*/

#pragma once

// Vector is used for list of tracks in TrackManager
// String is used for names of Tracks and Managers
#include <vector>
#include <string>

using std::string;
using std::vector;

// An enum of types of tracks
enum class TrackType {
    midi,
    audio,
    group,
    trigger,
    bus,
    send,
    master
};

// Define Track class
class Track {
// INSTANCE MEMBERS AND METHODS
private:
    // Track name (as shown in GUI)
    string trackName;

    // Type of Track (types defined in Track::TrackType)
    TrackType trackType;
public:
    // Constructor makes track with name and type
    Track(string name = "New Track", TrackType requestedType = TrackType::audio);

    // Function to rename Track
    void rename(string newName);
};