## Single pendulum simulation with air resistance - C++, SDL

The simulation contains one pendulum and renders its motion physically accurately by solving the differential equation, derived from laws of Newton, with Euler's method. The program gives out a window where the motion of the pendulum is simulated, utilizing the capabilities of SDL2 graphical library. The initial data of the pendulum is modifiable in `main.cpp`, meanwhile the program is runnable with `Main.exe`. In case we modify the main.cpp, we need to remake the `Main.exe` with going into the folder in cmd and typing `mingw32-make -f Makefile` into it.

The parameters in `main.cpp` are modifiable if we modify the 10th line of the code (`inga proba1(phi0,L,m,K)`). The parameters, that can be modified, are the following:

- `phi0`: initial angular displacement  
- `L`: the length of the pendulum  
- `m`: the mass of the pendulum  
- `k`: a coefficient including the drag factor, the cross-sectional area, and the density  

Pendulum Simulation utilizing the opportunities provided by the SDL2 graphical library.

After editing anything you can make a new "Main.exe" file by using the following command: 
mingw32-make -f Makefile
