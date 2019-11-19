#!/usr/bin/env bash

for file in as/*.as; do
  # shellcheck disable=SC2046
  # shellcheck disable=SC2016
  # shellcheck disable=SC2006
  out=$(basename "$file")
  out="${out%.*}"
  ../as/as "$file" "$out"
done