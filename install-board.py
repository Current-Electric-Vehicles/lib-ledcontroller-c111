#!/usr/bin/env python3.11

import os 
import sys
import shutil

def main():

    platforms_dir = os.environ.get('PLATFORMIO_PLATFORMS_DIR')
    if not platforms_dir:
        platforms_dir = os.path.join(os.environ.get('HOME'), ".platformio/platforms")

    if not platforms_dir or not os.path.exists(platforms_dir):
        print("ERROR: Platforms directory not found: {platforms_dir}".format(platforms_dir=platforms_dir))
        sys.exit(100)
        return

    platform_dir = os.path.join(platforms_dir, "espressif32/boards")
    if not os.path.exists(platform_dir):
        os.makedirs(platform_dir, exist_ok=True)
        print("Made directory: {platform_dir}".format(platform_dir=platform_dir))

    board_file = os.path.join(platform_dir, "c111-ledcontroller.json")
    shutil.copy("./board.json", board_file)
    print("Coppied board file to: {board_file}".format(board_file=board_file))

if __name__ == "__main__":
    main()

