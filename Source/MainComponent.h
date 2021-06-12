#pragma once

#include <JuceHeader.h>


/*
    ================================================================================

    Declarations of all GUI related classes are below

    ================================================================================
*/

class AllTracksWindow       : public juce::Component {

};

class TrackPluginsWindow    : public juce::Component {

};

class TrackSynthWindow      : public juce::Component {

};

class NormalPlugin          : public juce::Component {

};

class SourcePlugin          : public juce::Component {

};

class EffectLane            : public juce::Component {

};



//==================================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    juce::Slider outputVolumeSlider;
    juce::TextButton newTrackButton;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
