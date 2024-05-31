# yiffy

<div align="center">

![yiffy_logo_readme](https://github.com/MertGunduz/yiffy/assets/65850970/a9aad8c0-0b7e-4087-acd3-89c382d2ebf4)

</div>

## E621/E926 Search and Download TUI App

**Yiffy** is a basic Text User Interface (TUI) application developed to provide the process of searching, fetching, and downloading images from [e621](https://e621.net/) and [e926](https://e926.net/).

## Table of Contents
- [Dependencies](#dependencies)
- [Manual Build Instructions](#manual-build-instructions)
- [Guide to Yiffy Commands](#guide-to-yiffy-commands)
  - [Search and TUI (Text User Interface)](#search-and-tui-text-user-interface)
  - [API Fetch and Download](#api-fetch-and-download)
  - [Information and Help](#information-and-help)
  - [Data Management](#data-management)
  - [Configuration and Settings](#configuration-and-settings)

## Dependencies

### Mandatory Dependencies:
- `gcc`: The [GNU Compiler Collection](https://gcc.gnu.org/)
- `ascii-image-converter`: Convert images to ASCII art with this [tool](https://github.com/TheZoraiz/ascii-image-converter)
- `aria2`: A versatile [command-line download utility](https://aria2.github.io/)
- `cmake`: Cross-platform tools for [software building](https://cmake.org/)
- `make`: A utility to maintain groups of programs
- `libncurses-dev`: Developer’s libraries for [ncurses](https://invisible-island.net/ncurses/ncurses.html)

### Optional Dependencies:
- `tiv`: [Terminal ImageViewer](https://github.com/stefanhaustein/TerminalImageViewer), a tool to display images in the terminal.
- `timg`: [Terminal Image and Video Viewer](https://github.com/hzeller/timg), a tool to display images/videos in the terminal.

## Manual Build Instructions

Follow these steps to compile and install Yiffy manually:

```text
git clone https://github.com/MertGunduz/yiffy.git
cd yiffy
mkdir build && cd build
cmake ..
make
sudo cmake --install .
```

## Guide to Yiffy Commands

### Search and TUI (Text User Interface)
*Interact with the application through a user-friendly interface*
- **yiffy search tui argument:** 
  - `--search "tag1+tag2"`: Enhance your search experience with an intuitive TUI.

### API Fetch and Download
*Quickly fetch and download images based on tags*
- **yiffy api fetch arguments:** 
  - `--fetch "tag1+tag2"`: Retrieve URLs based on specified tags.
  - `--dfetch "tag1+tag2"`: Fetch URLs and download the images instantly.

### Information and Help
*Get help and information about Yiffy*
- **yiffy information menu arguments:** 
  - `--help`: Access a guide and list of commands.
  - `--version`: Check the current version of Yiffy.
  - `--github`: Visit the [Yiffy GitHub repository](https://github.com/MertGunduz/yiffy).
  - `--website`: Explore the official [Yiffy website](https://yiffy-cli.com/).
  - `--config`: Open the configuration menu.

### Data Management
*Manage your data within the Yiffy application*
- **yiffy data import-export arguments:**
  - `--import`: Import data into Yiffy.
  - `--export`: Export data from Yiffy.

### Configuration and Settings
*Adjust settings and configurations as per your preference*
- **yiffy configuration and settings arguments:** 
  - `--nsfw on/off`: Toggle NSFW (Not Safe for Work) and SFW (Safe For Work) content.
  - `--plog on/off`: Switch between PLOG (Print Log) for search.c and dfetch/fetch.c.
