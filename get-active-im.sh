#!/usr/bin/bash

./uim-status | grep branch | cut -d $'\n' -f 1 | cut -d $'\t' -f 2
