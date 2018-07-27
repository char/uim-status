#!/usr/bin/bash

./uim-status | grep branch | cut -d $'\t' -f 3 | tr $'\n' ' '

