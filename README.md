<div align="center">

![Yiffy Logo](https://github.com/MertGunduz/yiffy/assets/65850970/148fe232-6989-4c8f-b081-6c31126fa4b9)

</div>

# Yiffy: E621/E926 Search and Download TUI App

**Yiffy** is a basic Text User Interface (TUI) application designed to operate the searching, downloading, and retrieval of images from [e621](https://e621.net/) and [e926](https://e926.net/), providing a user-friendly experience.

## Table of Contents
- [Dependencies](#dependencies)
  - [Debian-Based Linux Distributions](#for-debian-based-linux-distributions)
  - [Arch-Based Linux Distributions](#for-arch-based-linux-distributions)
- [Installation Guide](#installation-guide)
- [Manual Build Instructions for Yiffy on Linux](#manual-build-instructions-for-yiffy-on-linux)
- [Comprehensive Guide to Yiffy Commands](#comprehensive-guide-to-yiffy-commands)
  - [Search and TUI (Text User Interface)](#search-and-tui-text-user-interface)
  - [API Fetch and Download](#api-fetch-and-download)
  - [Information and Help](#information-and-help)
  - [Data Management](#data-management)
  - [Configuration and Settings](#configuration-and-settings)

## Dependencies

### For Debian-Based Linux Distributions:
Ensure the optimal performance of Yiffy by installing the following packages:
- `gcc`: The [GNU Compiler Collection](https://gcc.gnu.org/)
- `build-essential`: A meta-package for building Debian packages
- `ascii-image-converter`: Convert images to ASCII art with this [tool](https://github.com/TheZoraiz/ascii-image-converter)
- `aria2`: A versatile [command-line download utility](https://aria2.github.io/)
- `cmake`: Cross-platform tools for [software building](https://cmake.org/)
- `make`: A utility to maintain groups of programs
- `libncurses-dev`: Developer’s libraries for [ncurses](https://invisible-island.net/ncurses/ncurses.html)

### For Arch-Based Linux Distributions:
Ensure the following packages are installed:
- Core Packages: `gcc`, `make`, `base-devel`
- Extra Packages: `aria2`, `cmake`, `ncurses` (Enable the multilib repository for `ncurses`)
- AUR (Arch User Repository): [`ascii-image-converter`](https://aur.archlinux.org/packages/ascii-image-converter)

## Installation Guide

Execute these commands in your terminal to get started with Yiffy:

```text
wget https://github.com/MertGunduz/yiffy/blob/main/install.sh
sudo chmod +x install.sh
./install.sh
```

## Manual Build Instructions for Yiffy on Linux

Follow these steps to compile and install Yiffy manually:

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
Interact with the application through a user-friendly interface:
- `yiffy search tui argument`: 
  - `--search "tag1+tag2"`: Enhance your search experience with an intuitive TUI.

### API Fetch and Download
Quickly fetch and download images based on tags:
- `yiffy api fetch arguments`: 
  - `--fetch "tag1+tag2"`: Retrieve URLs based on specified tags.
  - `--dfetch "tag1+tag2"`: Fetch URLs and download the images instantly.

### Information and Help
Get help and information about Yiffy:
- `yiffy information menu arguments`: 
  - `--help`: Access a guide and list of commands.
  - `--version`: Check the current version of Yiffy.
  - `--github`: Visit the [Yiffy GitHub repository](https://github.com/MertGunduz/yiffy).
  - `--website`: Explore the official [Yiffy website](https://yiffy-cli.com/).
  - `--config`: Open the configuration menu.

### Data Management
Manage your data within the Yiffy application:
- `yiffy data import-export arguments`: 
  - `--import`: Import data into Yiffy.
  - `--export`: Export data from Yiffy.

### Configuration and Settings
Adjust settings and configurations as per your preference:
- `yiffy configuration and settings arguments`: 
  - `--nsfw on/off`: Toggle NSFW (Not Safe for Work) and SFW (Safe For Work) content.
  - `--wgen on/off`: Switch between WGEN (a specific setting or feature) and its alternatives.
