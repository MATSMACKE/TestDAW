/*
  ==============================================================================

    GUIComponents.h
    Created: 14 Jun 2021 10:49:30pm
    Author:  matsm

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


/*
    ================================================================================

    Declarations of all GUI related classes are below

    ================================================================================
*/

class FileBrowser : public juce::Component {
    FileBrowser();
    ~FileBrowser();
};

class TransportBar : public juce::Component {

};

class TrackGUI : public juce::Component {

};

class AllTracksWindow : public juce::Component {

};

class TrackPlugins : public juce::Component {

};

class TrackSynthSection : public juce::Component {

};

class TrackEffectSection : public juce::Component {

};

class TrackModSection : public juce::Component {

};

class Plugin : public juce::Component {

};

class EffectPlugin : public Plugin {

};

class SourcePlugin : public Plugin {

};

class ModulatorPlugin : public Plugin {

};

class EffectLane : public juce::Component {

};


class GUIVars {
public:
    int transportHeight;
    int browserWidth;
    int trackPluginsHeight;
    int trackSegmentHeight;

    GUIVars(int transportHeight, int browserWidth, int trackPluginsHeight, int trackSegmentHeight);
};

