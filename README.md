# MandelbrotFractal
Program that generates / animates a colored Mandelbrot fractal, slowly zooming in. 

Instructions: 

Okay, you should just be able to pop this program into your IDE and run it. There are a few concerns though. 
First, expect the program to run pretty slow. The equation it's based on is pretty taxing.

Second, your mileage may vary with your respective IDE. 
I wrote this program on Visual Studio Code, so I know how to get it running there. 
Basically, all I did was set my "active solution platform" to x64 and my "active solution configuration" to release. 
Google told me that's supposed to make it go faster, so that's what I did. 

The final problem you might have is that "#include <SDL.h>" bit. You need to make sure you have access
to that file. First you want to libsdl.org, go to the download section, click SDL Releases then click 
on SDL 2.0. Download from the *development library*...now this step might be different for you, but since I was 
on Visual Studio I downloaded the "SDL2-devel-2.0.16-VC.zip" file. You might need the other one, or they might
have an updated file by the time you see this project. I trust your best judgment. Anyway, 
download it, save it somewhere. Now you gotta make sure the program has access to that SDL.h file in the 
folder. In Visual Studio Code, you just go up to project properties, hit VC++ Directories, and add the folder to 
your "Include Directories". After that, you should be good to go. 
