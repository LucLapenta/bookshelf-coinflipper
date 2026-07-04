# bookshelf coinflipper arduino

This directory contains source code and setup instctions to build the bookshelf coinflipper project using arduino libraries.

## Getting Started

### 1. Install initial dependencies

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
```

## Notes
