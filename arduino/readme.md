# bookshelf coinflipper arduino

This directory contains source code and setup instctions to build the bookshelf coinflipper project using arduino libraries.

## Getting Started

### 1. Install initial dependencies

*This project was developed using ubuntu 24 and does not currently provide instructions for using other operating systems.*

```
# ensure local bin directory exists
mkdir -p ~/.local/bin

# setup arduino cli
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=~/.local/bin sh
```

### 2. Setup Path

Ensure that you add the `~/.local/bin` directory to your path in your `~/.bashrc` file:

`export PATH=$PATH:~/.local/bin`

Then run `source ~/.bashrc`

### 3. Setup Arduino libraries

```
arduino-cli config init

arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

arduino-cli core update-index

arduino-cli core install rp2040:rp2040

arduino-cli lib install "Adafruit GFX Library"
arduino-cli lib install "Adafruit SSD1306"
```

### 4. Build project

from the root folder run:
```
arduino-cli compile --fqbn rp2040:rp2040:seeed_xiao_rp2040 arduino
```

### 5. Flashing:

To flash the compiled project to the board, set the board into bootloader mode by:
1. press and hold the BOOT button
2. press and hold the RESET button
3. release the RESET button
4. release the BOOT button

You should see the device connect to the PC as a USB mass storage device

run
```
arduino-cli upload -p UF2_Board --fqbn rp2040:rp2040:seeed_xiao_rp2040 arduino
```
