## Makefile for multiple files
Previously we had to compile a single file so things were straightforward. Here I'm using the same blink code but the functions are in a separate file along with its header.

Files are included by concatenating a string in variable `files`.

There are various options to build your files. You could, for example, build them separately and link them with additional command.

*If you need more advanced solution CMake is commonly used but it's cumbersome to configure correctly and I will avoid using it.*
