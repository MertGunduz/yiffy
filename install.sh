#!/bin/bash

# Define the repository URL
repository="https://github.com/MertGunduz/yiffy.git"

# List of required packages
required_packages=("git" "cmake" "gcc")

# Function to check if a command exists
command_exists() {
  command -v "$@" > /dev/null 2>&1
}

# Function to install packages
install_packages() {
  echo "Installing required packages..."
  if command_exists apt-get; then
    sudo apt-get update
    sudo apt-get install -y "${required_packages[@]}"
  elif command_exists yum; then
    sudo yum install -y "${required_packages[@]}"
  else
    echo "Unsupported package manager. Please install the required packages manually."
    exit 1
  fi
  echo "Packages installed successfully!"
}

# Welcome message
echo "This script will build yiffy from source."

# Check for required packages
for package in "${required_packages[@]}"; do
  if ! command_exists "$package"; then
    echo "Error: Missing required package: $package"
    install_packages
    break
  fi
done

# Ask the user if they want to continue
read -p "Do you want to continue? (y/n)? " input

# Main installation process
case $input in
  [Yy]* )
    echo "Starting..."
    if git clone "$repository"; then
      cd yiffy || exit
      mkdir -p build && cd build || exit
      if cmake .. && make; then
        sudo cmake --install .
        echo "yiffy installed successfully!"
      else
        echo "Error: Build failed."
        exit 1
      fi
    else
      echo "Error: git clone failed."
      exit 1
    fi
    ;;
  [Nn]* )
    echo "Installation aborted by the user."
    ;;
  * )
    echo "Invalid input, please run the script again and enter y or n."
    exit 1
    ;;
esac