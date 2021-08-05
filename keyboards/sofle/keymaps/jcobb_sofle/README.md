# My Sofle Keyboard
My layout for the sofle keyboard, will eventually update this with a screenshot of the layout.

## Compiling Notes:

- `qmk compile --kb sofle/rev1 --km sofle_keyboard_layout` Run this command to compile.
- Cannot have a keymap json file in the folder anywhere. It breaks the compling.

## Known Current issues (Unsure if keyboard or firmware issues)

- screen flickers when "sleeping"
  - I think this is due to the addition of Luna the keyboard pet.
- Screen on right half just doesn't work, might need to remove and resolder it, will look into after next 2 builds are done.

## Things I want to change or add:

### Macros:

Use the documentation on QMK's site for this, looks relatively easy to accomplish.

#### Shortcut for folding code to definitions:

- CMD+ALT+-
  - Command should be something like `SendString(SST(CMD)SST(ALT)"-")m`


### Key Layout Changes:

#### Keys:

- Flip the location of () and []

#### Rotary Encoders:

- Use a rotary encoder to change tabs in Chrome, VS Code, and Rider (need to see if the same keyboard shortcut works in other places.)
  - ALT+TAB == Forward
  - ALT+SHIFT+TAB == Backwards
  -

### Other Changes:

- Change out the `XXXXX` Key codes for `KC_NO`
- Change out `_____` for `KC_TRNS`

These are not necessariy changes and might make the key map more difficult to read.

## Other Ideas:
Should I hard code things like shrug, look of disapproval, tflip, and the various other text expansion thigns I use? I'm thinking these aren't the best ideas and will use up some of the keys I have left.

## Current Layout:

This block of JSON was created using the conversion tool with qmk (see script in this repo).