#!/usr/bin/env bash

for file in bin/*; do
  echo "\e[1;32mRunning $file...\e[0m"
  ../src/tinivm -i "$file"
  echo
done