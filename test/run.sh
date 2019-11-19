#!/usr/bin/env bash

for file in bin/*; do
  echo "\e[1;32mRunning $file...\e[0m"
  ../tinivm -i "$file"
  echo
done