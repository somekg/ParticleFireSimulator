// Particles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "ErrorInfo.h"
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace acg;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initialising SDL..." << endl;
    }

    Swarm swarm;

    while (true) {

        int elapsed = SDL_GetTicks();
       
        swarm.update(elapsed);
                

        unsigned char red = (unsigned char)((1 + cos(elapsed * 0.01)) * 128);
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.3)) * 128);
        unsigned char blue = (unsigned char)((1 + cos(elapsed * 0.001)) * 128);


        

        const Particle* const pParticles = swarm.getParticles();

        for (int i = 0; i < swarm.NPARTICLES; i++) {
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y  * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x, y, red, green, blue);

        }
        screen.boxBlur();

        screen.update();

        if (screen.processEvents() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
