#include <iostream>
#include <fstream> // files manipulation
#include <complex> // complex numbers
using namespace std;
float width = 600;
float height = 600;

int main(){
	ofstream my_Image ("mandelbrot.ppm");
	if (my_Image.is_open ()){
		my_Image << "P3\n" << width << " " << height << " 255\n";
		for(int i = 0; i < width; i++){
			for (int j = 0; j < height; j++){
				my_Image << 255 << " " << 0 << ' ' << 0 << "\n";
			}
		}
		my_Image.close();
	}
	else cout << "couldn't open the file";
	return 0;
}

// https://en.wikipedia.org/wiki/Netpbm_format
// https://medium.com/farouk-ounanes-home-on-the-internet/mandelbrot-set-in-c-from-scratch-c7ad6a1bf2d9
