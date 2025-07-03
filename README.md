## Single pendulum simulation with air resistance - C++, SDL

The simulation contains one pendulum and renders its motion physically accurately by solving the differential equation, derived from laws of Newton, with Euler's method. The program gives out two graphs after solving the equatian and its parameters are modifiable via `datas.txt`, meanwhile the program is runnable with `main.exe`.

The parameters in `datas.txt` are the following:

- `phi0`: initial angular displacement  
- `L`: the length of the pendulum  
- `m`: the mass of the pendulum  
- `k`: a coefficient including the drag factor, the cross-sectional area, and the density  

Pendulum Simulation utilizing the opportunities provided by the SDL2 graphical library.

After editing anything you can make a new "Main.exe" file by using the following command: 
mingw32-make -f Makefile
