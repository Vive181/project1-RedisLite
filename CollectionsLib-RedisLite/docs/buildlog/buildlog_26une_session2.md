### Date: June 26
### Duration: 120 minutes

## Goal:build the parser for redis lite 

## Problem Encountered:

1. Commands with missing arguments (example like SET name) were not handled correctly.
2. Extra spaces in the input caused wrong parsing.
3. The parser did not correctly distinguish between valid and invalid commands it cannot handle unknown commands other than valid commands like (set,get,del and contains).

## What I Tried:

1. Used stringstream to split the input into command, key, and value.
2. Tested the parser with different inputs such as SET, GET, DEL, and invalid commands.
3. Added validation to check whether the required arguments were present before processing the command.

## Outcome:

1. Successfully built a parser that correctly extracts the command, key, and value.
2. The parser now handles supported commands and reports unknown or incomplete commands appropriately.
