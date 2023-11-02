#!/bin/bash

# Set the repository URL
repository="https://github.com/MertGunduz/yiffy.git"

# Welcome message
echo "This is an example install.sh file. It doesn't check for required packages needed to install yiffy."
echo "Please ensure you have installed the necessary packages before proceeding. Check the GitHub page for more information."

# Prompt user to continue
read -p "This script will build yiffy from source. Do you want to continue? (y/n): " input

# Main logic
case "$input" in
    n|N)
        echo "Installation cancelled by user."
        ;;
    y|Y)
        echo "Starting installation..."

        # Clone the repository
        if git clone "$repository"; then
            cd yiffy || exit 1
            mkdir -p build && cd build || exit 1
            
            # Configure and build the project
            if cmake .. && make; then
                # Install the project
                sudo cmake --install .
                echo "Installation completed successfully."
            else
                echo "Error: Build failed. Please check the output for details."
            fi
        else
            echo "Error: Unable to clone the repository. Please check your internet connection and try again."
        fi
        ;;
    *)
        echo "Invalid input. Please run the script again and enter 'y' to continue or 'n' to cancel."
        ;;
esac
