

# AbletonMIDI

A simple C++ tool that sends MIDI notes into Ableton Live using IAC virtual MIDI buses.  
Designed to simulate a real-time MIDI performance with:
- Continuous 8th notes for 64 bars
- A snare hit on beat 3 of every bar (routed to a separate track)

---

## 🎛 Features

- Uses **RtMidi** for cross-platform MIDI output
- Sends MIDI through two IAC Driver buses:
  - **Bus 1**: Main notes (e.g., C4)
  - **Bus 2**: Snare hits (e.g., GM Note 38)
- Built with clean modular C++ architecture
- Compatible with Ableton Live or any DAW that accepts MIDI input

---

## 🛠 Project Structure

```
AbletonMidi/
├── CMakeLists.txt
├── include/
│   ├── MidiSender.h        # MIDI sending class
│   └── Timing.h            # Utility sleep function
├── src/
│   ├── main.cpp            # Main playback loop
│   ├── MidiSender.cpp      # RtMidi wrapper
│   └── Timing.cpp          # Timing implementation
```

---

## 🧰 Requirements

- macOS or Linux (with IAC or virtual MIDI support)
- [RtMidi](https://github.com/thestk/rtmidi)
- CMake 3.10+
- A DAW like **Ableton Live** with MIDI inputs configured

---

## 🔧 Setup

### 1. Enable IAC Buses (macOS)
Open **Audio MIDI Setup** → MIDI Studio → **IAC Driver**  
- Enable **Device is online**
- Add two ports:
  - `IAC Driver Bus 1`
  - `IAC Driver Bus 2`

### 2. In Ableton Live
- **Preferences → Link/Tempo/MIDI**
- Enable **Track** input for both IAC buses
- Create two MIDI tracks:
  - Input: IAC Driver Bus 1 → record main notes
  - Input: IAC Driver Bus 2 → record snare

---

## 🧪 Build Instructions

```bash
brew install rtmidi cmake
mkdir build && cd build
cmake ..
make
./AbletonMidi
```

---

## 🥁 Output Logic

- Tempo: 120 BPM
- Duration: 64 bars
- Sends:
  - Note 60 (C4) as 8th notes on Bus 1
  - Note 38 (Snare) on beat 3 via Bus 2

---

## 📄 License

MIT License.  
Feel free to use and extend this for live MIDI control, generative music, or DAW automation.
