# galatea-rev1-feqma
Keymap and rules for the Galatea PCB F12 WK

Steps in QMK MSYS development environment:  
* Create keymap  
qmk new-keymap -kb studiokestra/galatea -km feqma  

* Copy in the rules.mk and keymap.c files to the ./keyboards/studiokestra/galatea/keymaps/feqma folder  

* Compile  
qmk compile -kb studiokestra/galatea -km feqma  
