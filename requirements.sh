#!/bin/bash
# Check to see if Homebrew is installed, and install it if it is not
command -v brew >/dev/null 2>&1 || { echo >&2 "Installing Homebrew Now"; \
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"; }

if brew ls --versions macosvpn > /dev/null; then
  # The package is installed
  echo OK
else
  # The package is not installed
  brew install macosvpn
fi
