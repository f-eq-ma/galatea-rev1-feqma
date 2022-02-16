# galatea-rev1-feqma
Keymap and rules for the Galatea PCB F12 WK

Steps in QMK MSYS development environment:  
* Create keymap  
qmk new-keymap -kb studiokestra/galatea -km feqma  

* Copy in the rules.mk and keymap.c files to the ./keyboards/studiokestra/galatea/keymaps/feqma folder  

* Compile  
qmk compile -kb studiokestra/galatea -km feqma  



Note:  See https://github.com/f-eq-ma/bdn9 for AutoHotKey files for iTunes  

Note:  On compile, if you get an "Invalid return_code: 2816", then you will need to manually remove some of the keyboards out of the "keyboards" directory.  I removed the c*, m*, and handwired directories.   Known issue: https://github.com/qmk/qmk_distro_msys/issues/93  
