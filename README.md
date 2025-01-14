# ESP32 Audio Visualizer

![audiospektrikytkykuva](https://github.com/user-attachments/assets/5dd221c2-2dae-4e4f-b6a6-42b62885080b)

## Project Description

The ESP32 Audio Visualizer is a project that leverages the powerful ESP32 microcontroller to create an audio visualizer. 
This project involves designing the hardware and software to capture audio signals with an electret microphone, process them, and display the audio spectrum visually using an OLED display.

## KiCad Component Models

This project uses several KiCad component models to design and layout the PCB. Below are the details of the main components used:

### 1. Electret Microphone Amplifier - MAX4466 with Adjustable Gain

- **Symbol File:** [1063.kicad_sym](https://github.com/leeviekd/ESP32-audio-visualizer/blob/main/KiCad_component_models/1063/1063.kicad_sym)
- **Footprint File:** [MODULE_1063.kicad_mod](https://github.com/leeviekd/ESP32-audio-visualizer/blob/main/KiCad_component_models/1063/1063.pretty/MODULE_1063.kicad_mod)
- **Manufacturer:** Adafruit Industries
- **Description:** Electret Microphone Amplifier with adjustable gain.

### 2. 0.96” 128 X 64 Monochrome Graphic OLED Display Module - I2C

- **Symbol File:** [DM-OLED096-636.kicad_sym](https://github.com/leeviekd/ESP32-audio-visualizer/blob/main/KiCad_component_models/DM-OLED096-636/DM-OLED096-636.kicad_sym)
- **Footprint File:** [MODULE_DM-OLED096-636.kicad_mod](https://github.com/leeviekd/ESP32-audio-visualizer/blob/main/KiCad_component_models/DM-OLED096-636/MODULE_DM-OLED096-636.kicad_mod)
- **Manufacturer:** Displaymodule
- **Description:** 0.96” 128 X 64 Monochrome Graphic OLED Display Module with I2C interface.

## Video demo

https://github.com/user-attachments/assets/7c18a615-56e0-4a1f-8cac-e827901379dd

