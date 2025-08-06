#include "MidiSender.h"
#include "Timing.h"
#include <iostream>

int main() {
    MidiSender mainTrack;
    MidiSender snareTrack;

    mainTrack.listPorts();

    if (!mainTrack.openPort(0)) return -1;
    if (!snareTrack.openPort(1)) return -1;

    int bpm = 120;
    int beatsPerBar = 4;
    int bars = 64;
    double noteLengthSeconds = 0.5; // 8th note at 120 BPM

    int mainNote = 60;   // Middle C
    int snareNote = 38;  // Acoustic Snare

    int totalBeats = beatsPerBar * bars;

    for (int i = 0; i < totalBeats * 2; ++i) {
        mainTrack.sendNoteOn(mainNote, 100);
        sleepMs(int(noteLengthSeconds * 1000));
        mainTrack.sendNoteOff(mainNote, 100);

        if (i % (beatsPerBar * 2) == 4) { // Beat 3
            snareTrack.sendNoteOn(snareNote, 110);
            sleepMs(int(noteLengthSeconds * 1000));
            snareTrack.sendNoteOff(snareNote, 110);
        }
    }
}