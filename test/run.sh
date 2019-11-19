#!/usr/bin/env bash

for file in *.tvm; do
  echo "\033[33;32mRunning $file...\e[0m"
  ../tinivm -i "$file"
  echo
done