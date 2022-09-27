## Blinking outside of Arduino IDE

### What IDE should I use?
- **Microchip Studio** is a dedicated IDE from AVR manufacturer.
- **Visual Studio Code with Platform.io plugin** is the easiest option, it will set up everything for you just like Arduino IDE.
- **Visual Studio Code with custom toolchain.** Difficult to use but most flexible. *I will use that option for rest of our examples because we are doing bare-metal. You can copy-paste code to Arduino ide or Platform.io if you don’t want that.*

*There are others but these were the ones I’ve used with AVR.*

### What I need to install for custom setup?
- **AVR-GCC** to compile the code for AVR.
- **AVR-DUDE** to upload the compiled code through programmer.
- **GNU-MAKE** to automate the build process with make files. *Usually CMake is used for more complex builds.*

You need to add them to your system path. This page can help: http://fab.cba.mit.edu/classes/863.16/doc/projects/ftsmin/windows_avr.html

**To check if everything works, open terminal in VS Code and type:**

     avr-gcc -v
     avrdude -v
     make -v

### Things to change in code:

- **No setup and loop functions.** In C/C++ the `main` function is used as a starting point.
- **Includes from AVR library.** Read next section for instruction.
- **The F_CPU macro** to set the information about frequency (used by functions such as delay). *It won’t set the actual frequency, to do that you need to set the **AVR fuses** when uploading your code. If you’re using Arduino Uno default fuses are already set.*

### Visual Studio Code can’t find headers and macros issue:

1. Watch this video https://www.youtube.com/watch?v=b2Ms6v8kRv4 
2. Add includes from avr-gcc folder, in my case it’s C:/avr8-gnu-toolchain/avr/include
3. In defines add `"__AVR_ATmega328__"` or include it as `#define` in each of your files.

*To do that you probably need C/C++ extension for VS Code.*

### Compiling and uploading the code:
To do that, open the terminal in VS Code, make sure you’re in the project main folder (where makefile is located). The makefile contains ready to use commands so you don’t have to write them each time. Understanding how this work is out of scope for my examples.
*Included makefile is intended for a single file, to use many files check next example. You need to add them manually*

- **Compiling:** type `make create`
- **Uploading:** set parameters in makefile, then type `make upload`

*You can do both at once by typing* `make create upload`

I'm using the **Pololu USB AVR programmer v2** to upload the code. If you want to use your Arduino UNO board again with Arduino IDE make sure to burn the bootloader in *Aruduino IDE > tools > Burn Bootloader*.

