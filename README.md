<div align="center">
  
![yiffy logo](https://github.com/MertGunduz/yiffy/assets/65850970/148fe232-6989-4c8f-b081-6c31126fa4b9) 

</div>

# Yiffy: E621/E926 Search and Download TUI App

Yiffy is a basic TUI application crafted for the purpose of searching, downloading, and retrieving images from e621 and e926, offering a user-friendly experience.

## Dependencies

### For Debian-Based Linux Distributions:
Ensure the following packages are installed for optimal performance:
- `gcc`: The GNU Compiler Collection
- `build-essential`: A package containing an informational list of packages which are considered essential for building Debian packages
- `ascii-image-converter`: A tool to convert images into ASCII art
- `aria2`: A lightweight multi-protocol & multi-source command-line download utility
- `cmake`: An open-source, cross-platform family of tools designed to build, test and package software
- `make`: A utility for directing compilation
- `libncurses-dev`: Developer’s libraries for ncurses

### For Arch-Based Linux Distributions:
Ensure the following core and extra packages are installed:
- Core Packages: `gcc`, `make`, `base-devel`
- Extra Packages: `aria2`, `cmake`, `ncurses` (Note: Enable the multilib repository for `ncurses`)
- AUR (Arch User Repository): `ascii-image-converter`

## Installation Guide

Execute the following commands in your terminal to install Yiffy:

```text
wget https://github.com/MertGunduz/yiffy/blob/main/install.sh
sudo chmod +x install.sh
./install.sh
```

## Manual Build Instructions for Yiffy on Linux

To manually compile and install Yiffy on a Linux system, follow these commands:

```text
git clone https://github.com/MertGunduz/yiffy.git
cd yiffy
mkdir build && cd build
cmake ..
make
sudo cmake --install .
```

## Comprehensive Guide to Yiffy Commands

### Search and TUI (Text User Interface)

- `yiffy search tui argument`: 
  - `--search "tag1+tag2"`: Engage with a user-friendly TUI, enhancing the search experience.

### API Fetch and Download

- `yiffy api fetch arguments`: 
  - `--fetch "tag1+tag2"`: Quickly fetch URLs based on specified tags.
  - `--dfetch "tag1+tag2"`: Fetch URLs and initiate download of the images.

### Information and Help

- `yiffy information menu arguments`: 
  - `--help`: Display a helpful guide and list of commands.
  - `--version`: Show the current version of Yiffy.
  - `--github`: Direct you to the Yiffy GitHub repository.
  - `--website`: Take you to the official Yiffy website.
  - `--config`: Present the configuration menu.

### Data Management

- `yiffy data import-export arguments`: 
  - `--import`: Import data into the Yiffy application.
  - `--export`: Export data from the Yiffy application.

### Configuration and Settings

- `yiffy configuration and settings arguments`: 
  - `--nsfw on/off`: Toggle between Not Safe for Work (NSFW) and Safe For Work (SFW) content.
  - `--wgen on/off`: Toggle between WGEN (a specific setting or feature) and its alternative.
