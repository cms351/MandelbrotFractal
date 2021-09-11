# MandelbrotFractal
Program that generates / animates a colored Mandelbrot fractal, slowly zooming in. 

Instructions: 

Okay, you should just be able to pop this program into your IDE and run it. There is a few concerns though. 
First, this program is super taxing on your computer - i.e. it's slow by the nature of what we're working 
with. You're going to want to do everything you can to get it running as fast as possible. I don't know 
your IDE, but I wrote this program on Visual Studio Code, so I can tell you what I did and maybe that'll
help? Basically, all I did was set my "active solution platform" to x64 and my "active solution 
configuration" to release. Google told me that's supposed to make it go faster, so that's what I did. 

The other problem you might have is that "#include <SDL.h>" bit. You need to make sure you have access
to that file. First you want to libsdl.org, go to the download section, click SDL Releases then click 
on SDL 2.0. Download *development library*...now this step might be different for you, but since I was 
on Visual Studio I downloaded the "SDL2-devel-2.0.16-VC.zip" file. You might need the other one. Anyway, 
download it, save it somewhere. Now you gotta make sure the program has access to that SDL.h file in the 
folder. In Visual Studio Code, you just go up to project properties, hit VC++ Directories, and add the folder to 
your "Include Directories". If you're not in VSCode, not gonna lie, not sure what exactly what you need to 
do, but I have faith you'll figure it out. If you're reading this, you're probably an employer or something
and know way more than me anyway. I think the code is pretty good though!
