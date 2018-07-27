# uim-status

A small utility to get the current status of `uim`.

## Why?

uim doesn't have a command-line tool to see which IM is currently active, with this tool, you can run something like `uim-status | grep branch | cut -d $'\n' -f 1 | cut -d $'\t' -f 2` to get the name of the currently selected IM.
