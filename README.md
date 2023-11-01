<div align="center">
  
![yiffy logo](https://github.com/MertGunduz/yiffy/assets/65850970/148fe232-6989-4c8f-b081-6c31126fa4b9) 

</div>

# Yiffy: E621/E926 Search and Download Terminal App

Yiffy is a terminal application designed to search, download, and fetch images from e621 and e926.

## System Dependencies

### For Debian-Based Distributions:
- `gcc`
- `build-essential`
- `ascii-image-converter`
- `aria2`
- `cmake`
- `make`
- `libncurses-dev`

### For Arch-Based Distributions:
- `gcc` (core)
- `make` (core)
- `base-devel` (core)
- `aria2` (extra)
- `cmake` (extra)
- `ncurses` (extra, multilib repo should be enabled)
- `ascii-image-converter` (AUR)

## Building Yiffy on Linux

Follow these commands to build Yiffy on a Linux system:

```bash
git clone https://github.com/MertGunduz/yiffy.git
cd yiffy
mkdir build
cd build
cmake ..
make
sudo cmake --install .
```

## Yiffy Commands

### Search and TUI Interface
- `yiffy search tui argument`
  - `--search "tag1+tag2"`: Opens a TUI interface.

### API Fetch and Download
- `yiffy api fetch arguments`
  - `--fetch "tag1+tag2"`: Fetches URLs.
  - `--dfetch "tag1+tag2"`: Fetches URLs and downloads.

### Information and Help Menu
- `yiffy information menu arguments`
  - `--help`: Outputs the help menu.
  - `--version`: Outputs the version information.
  - `--github`: Provides the GitHub repository link.
  - `--website`: Provides the official website link.
  - `--config`: Outputs the configuration menu.

### Data Import and Export
- `yiffy data import-export arguments`
  - `--import`: Imports data to the program.
  - `--export`: Exports data from the program.

### Configuration and Settings
- `yiffy configuration and settings arguments`
  - `--nsfw on/off`: Switch between NSFW and SFW options.
  - `--wgen on/off`: Switch between WGEN and non-WGEN options.
