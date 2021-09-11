#include <SDL.h> 
#include <Windows.h>

int WIDTH = 400; 
int HEIGHT = 400;

long double min = -2.84; 
long double max = 1.0;
long double factor = 1; 
int MAX_ITERATIONS = 100; 

long double map(long double value, long double inputMin, long double inputMax, long double outputMin, long double outputMax) {
	// (x - input minimum) * 'output range' / 'input range' + output minimum
	// got this equation from the internet not gonna lie. 
	return (value - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin; 
}

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING); 

	SDL_Window* window; 
	SDL_Renderer* renderer; 
	SDL_Event event; 

	SDL_CreateWindowAndRenderer(720, 450, 0, &window, &renderer); 
	SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT); 

	int count = 0; 
	
	while (1)
	{

		max -= 0.1 * factor; 
		min += 0.15 * factor; 
		factor *= 0.9349; 
		MAX_ITERATIONS += 5; 

		if (count > 30) {
			MAX_ITERATIONS *= 1.02; 
		}


		SDL_RenderPresent(renderer); 

		// from wikipedia
		// The Mandelbrot Set is the set of complex numbers c for which the function f[c](z) = z^2 + c does not diverge when iterated from z = 0, i.e., 
		// for which sequence f[c](0), f[c](f[c](0)), etc., remains bounded in absolute value. 

		// basically, you have this function z^2 + c. You iterate that function a number of times, and the goal is to see how many iterations it takes
		// for the function to shoot off to infinity for different values. The color of the pixel is basically determined by the number of iterations
		// for the function to shoot into infinity. The function just creates cool looking pictures. 

		// c is x + yi. y is the y coordinate on the screen, i is the square root of negative one. x is the x coordinate on the screen. 

		// c is a bit annoying to work with because inherently, since i is the square root of negative one, it would cause an computational error if we
		// just tried to throw that equation into the computer. Instead we use (x + yi)^2. (x + yi)(x + yi) = x^2 + 2xyi + i^2. Simplify to 
		// x^2 + 2xyi + y^2(-1). Simplify that to x^2 + 2xyi - y^2. At first I thought this wasn't much better, but i is actually much easier to 
		// *simulate* in this equation. 

		for (int x = 0; x < WIDTH; x++) { // x = a 

			// this just allows you to exit the screen
			if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
				return 0; 
			}
			if (GetKeyState('Q') && 0x8000) {
				return 0; 
			}

			for (int y = 0; y < HEIGHT; y++) { // y = b
				long double a = map(x, 0, WIDTH, min, max); 
				long double b = map(y, 0, HEIGHT, min, max); 

				// store initial values of x and y
				long double ai = a; 
				long double bi = b; 

				// initialization
				int counter = 0; 

				for (int i = 0; i < MAX_ITERATIONS; i++) {

					long double pt1 = a * a - b * b; // effectively x^2 - y^2
					long double pt2 = 2 * a * b; // effectively 2xy
					
					a = pt1 + ai; 
					b = pt2 + bi; 

					// if a + b is greater than 2, it meets my standard of "shooting off into infinity" 
					if ((a + b) > 2) {
						break; 
					}

					counter++; 
				}

				int brightness = map(counter, 0, MAX_ITERATIONS, 0, 255); 
	
				if ( (counter == MAX_ITERATIONS) || (brightness < 20) ) {
					brightness = 0; 
				}

				int red, green, blue;
				red = brightness; 
				green = map((brightness * brightness), 0, (255 * 255), 0, 255); 
				blue = map(sqrt(brightness), 0, sqrt(255), 0, 255); 

				SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
				SDL_RenderDrawPoint(renderer, x, y);
				
				
			
			}
		}
	
		count++; 
	}

	return 0; 
}