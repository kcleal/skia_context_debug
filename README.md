
What is this?
=============

This repository is a minimal working example, demonstrating a problem when using GLFW and skia over an ssh -X
connection. This issue occurs when ssh'ing from a Mac to a Linux machine. Linux-Linux connections seem to work though.

This is built on a linux machine (ubuntu tested).

The skia library comes pre-built and was downloaded from JetBrains: https://github.com/JetBrains/skia-build/releases/download/m93-87e8842e8c/ 

To reproduce the issue, you will need to log on to a Linux (ubuntu) server from your loca Mac using "ssh -X".

Next build this repo. To build you will need to have a system copy of glfw3 and X11 libraries on your linux machine::

    git clone https://github.com/kcleal/skia_context_debug
    cd skia_context_debug
    make
    .a.out

Output is::

    ./a.out
    libGL error: No matching fbConfigs or visuals found
    libGL error: failed to load driver: swrast
    Error: skia GrGLInterface was not valid
