#!/usr/bin/env bash

for file in bin/*; do
  echo "\e[1;33mRunning $file...\e[0m"
  if ../src/tinivm -i "$file"; then
      echo "\e[1;32mSuccess, no errors.\e[0m"
  else
      echo "\e[1;31mFailure, errors occured.\e[0m"
  fi
  echo
done
