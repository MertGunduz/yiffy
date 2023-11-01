<img width="74" align="left" alt="commision_unix" src="https://github.com/MertGunduz/yiffy/assets/65850970/148fe232-6989-4c8f-b081-6c31126fa4b9">

# yiffy

yiffy is a terminal app for searching/downloading/fetching images from e621/e926 <br>

# Dependencies needed for Debian based distro's
- gcc
- build-essential
- ascii-image-converter
- aria2
- cmake
- make
- libncurses-dev

# Dependencies needed for Arch based distro's
- gcc (core)
- make (core)
- base-devel (core)
- aria2 (extra)
- cmake (extra)
- ncurses (extra, multililib repo should be enabled)
- ascii-image-converter (AUR)

# Building on linux
```
git clone https://github.com/MertGunduz/yiffy.git
```
```
cd yiffy
```
```
mkdir build
```
```
cd build
```
```
cmake ..
```
```
make
```
```
sudo cmake --install .
```

# Commands

### yiffy search tui argument  
```--search "tag1 tag2"```   opens a tui interface

### yiffy api fetch arguments
```--fetch "tag1 tag2"```    fetches urls<br>
```--dfetch "tag1 tag2"```   fetches urls and downloads

### yiffy information menu arguments
```--help```              outputs the help menu<br>
```--version```           outputs the version menu<br>
```--github```            outputs the github menu<br>
```--website```           outputs the website menu<br>
```--config```            outputs the configuration menu<br>

### yiffy data import-export arguments
```--import```            imports the data to program<br>
```--export```            exports the data from program<br>

### yiffy configuration and settings arguments
```--nsfw on/off```     switches to nsfw/sfw options<br>
```--wgen on/off```     switches to wgen/non-wgen option

