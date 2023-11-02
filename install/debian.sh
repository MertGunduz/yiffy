#!/bin/bash

set -e

if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 
   exit 1
fi

# Set the repository URL
repository="https://github.com/MertGunduz/yiffy.git"

# Dependencies
dependencies=("git" "gcc" "build-essential" "aria2" "cmake" "make" "libncurses-dev")

# Function to check if a package is installed
is_installed() {
    dpkg -l "$1" &> /dev/null
}

# Function to install a package
install_package() {
    echo "Installing $1..."
    apt-get install -y "$1"
}

# Check for missing dependencies
missing_dependencies=()
for package in "${dependencies[@]}"; do
    if ! is_installed "$package"; then
        missing_dependencies+=("$package")
    fi
done

# Install missing dependencies
if [ ${#missing_dependencies[@]} -ne 0 ]; then
    echo "The following dependencies are missing and will be installed: ${missing_dependencies[*]}"
    read -p "Do you want to continue? (y/n): " input
    if [[ "$input" =~ ^[Yy]$ ]]; then
        apt-get update
        apt-get upgrade -y
        for package in "${missing_dependencies[@]}"; do
            install_package "$package"
        done
    else
        echo "Installation cancelled by user."
        exit 1
    fi
else
    echo "All dependencies are already installed."
fi

# Check if ascii-image-converter is installed
if ! command -v ascii-image-converter &> /dev/null; then
    echo "ascii-image-converter is not installed. Installing..."
    snap install ascii-image-converter
else
    echo "ascii-image-converter is already installed."
fi

# Prompt user to continue with yiffy installation
read -p "This script will build yiffy from source. Do you want to continue? (y/n): " input

# Main logic
case "$input" in
    n|N)
        echo "Installation cancelled by user."
        ;;
    y|Y)
        echo "Starting installation..."

        # Clone the repository
        if git clone "$repository" yiffy; then
            cd yiffy || exit 1
            mkdir -p build && cd build || exit 1
            
            # Configure and build the project
            if cmake .. && make; then
                # Install the project
                cmake --install .
                echo "Installation completed successfully."
            else
                echo "Error: Build failed. Please check the output for details."
                exit 1
            fi
        else
            echo "Error: Unable to clone the repository. Please check your internet connection and try again."
            exit 1
        fi
        ;;
    *)
        echo "Invalid input. Please run the script again and enter 'y' to continue or 'n' to cancel."
        exit 1
        ;;
esac