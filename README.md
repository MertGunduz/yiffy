<div align="center">

![Yiffy Logo](https://github.com/MertGunduz/yiffy/assets/65850970/148fe232-6989-4c8f-b081-6c31126fa4b9)

</div>

# Yiffy: E621/E926 Search and Download TUI App

**Yiffy** is a basic Text User Interface (TUI) application developed to provide the process of searching, fetching, and downloading images from [e621](https://e621.net/) and [e926](https://e926.net/).

## Table of Contents
- [Dependencies](#dependencies)
- [Installation Guide](#installation-guide)
- [Manual Build Instructions for Yiffy on Linux](#manual-build-instructions-for-yiffy-on-linux)
- [Comprehensive Guide to Yiffy Commands](#comprehensive-guide-to-yiffy-commands)
  - [Search and TUI (Text User Interface)](#search-and-tui-text-user-interface)
  - [API Fetch and Download](#api-fetch-and-download)
  - [Information and Help](#information-and-help)
  - [Data Management](#data-management)
  - [Configuration and Settings](#configuration-and-settings)

## Dependencies

### Mandatory Dependencies:
Ensure the optimal performance of Yiffy by installing the following packages:
- `gcc`: The [GNU Compiler Collection](https://gcc.gnu.org/)
- `ascii-image-converter`: Convert images to ASCII art with this [tool](https://github.com/TheZoraiz/ascii-image-converter)
- `aria2`: A versatile [command-line download utility](https://aria2.github.io/)
- `cmake`: Cross-platform tools for [software building](https://cmake.org/)
- `make`: A utility to maintain groups of programs
- `libncurses-dev`: Developer’s libraries for [ncurses](https://invisible-island.net/ncurses/ncurses.html)

### Optional Dependencies:
- `tiv`: [Terminal ImageViewer](https://github.com/stefanhaustein/TerminalImageViewer), a tool to display images in the terminal.

## Installation Guide

Please select your Linux distribution for specific installation instructions:

<table>
  <tr>
    <td align="center" width="96">
        <img src="https://github.com/MertGunduz/yiffy/assets/65850970/140887f1-3ae3-4f96-a039-fa98f8a231de" width="56" height="56" alt="Debian, Ubuntu">
        <br><a href="install/debian.sh">Debian</a>
    </td>
    <td align="center" width="96">
        <img src="https://github.com/MertGunduz/yiffy/assets/65850970/20f4135f-422f-471f-a825-491c603e03b5" width="56" height="56" alt="Fedora">
        <br><a href="install/fedora.sh">Fedora</a>
    </td>
    <td align="center" width="96">
        <img src="https://github.com/MertGunduz/yiffy/assets/65850970/7feb9dd9-7190-48ca-8cbd-2acd5160bc23" width="56" height="56" alt="Arch Linux">
        <br><a href="install/arch.sh">Arch</a>
    </td>
    <td align="center" width="96">
        <img src="https://github.com/MertGunduz/yiffy/assets/65850970/8ef75ca9-b821-4918-94f3-5ac95465e2bd" width="56" height="56" alt="Gentoo">
        <br><a href="install/gentoo.sh">Gentoo</a>
    </td>
    <td align="center" width="96">
        <img src="https://github.com/MertGunduz/yiffy/assets/65850970/66dea202-b543-48b7-9d7e-9d4dda909060" width="56" height="56" alt="FreeBSD">
       <br><a href="install/bsd.sh">FreeBSD</a>
    </td>
  </tr>
</table>


## Manual Build Instructions

Follow these steps to compile and install Yiffy manually:

```sh
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
  - `--wgen on/off`: Switch between WGEN (a website building feature) for search.c and dfetch/fetch.c.

The above documentation provides a comprehensive and clear guide to Yiffy, ensuring a seamless and enjoyable user experience.
