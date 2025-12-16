# Fractol

Interactive fractal renderer that visualizes Mandelbrot and Julia sets with zoom functionality.

## Description

Fractol is a C-based graphical application that generates and displays beautiful fractal patterns. The project uses the MiniLibX library to create an interactive window where users can explore the infinite complexity of mathematical fractals.

## Features

- **Mandelbrot Set**: Classic fractal visualization
- **Julia Set**: Customizable Julia sets with user-defined complex parameters
- **Interactive Zoom**: Mouse wheel zoom in/out functionality
- **Real-time Rendering**: Dynamic recalculation and display of fractals
- **Color Mapping**: Beautiful color gradients based on iteration counts

## Requirements

- GCC compiler
- MiniLibX library (Linux version)
- X11 development libraries
- Make

## Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd fractol
```

2. Build the project:
```bash
make
```

This will compile the fractol executable along with the required libft library.

## Usage

### Mandelbrot Set
```bash
./fractol mandelbrot
```

### Julia Set
```bash
./fractol julia <real> <imaginary>
```

Example:
```bash
./fractol julia -0.7269 0.1889
```

## Controls

- **Mouse Wheel**: Zoom in/out
- **ESC Key**: Exit the program
- **Window Close Button**: Exit the program

## Project Structure

```
fractol/
├── main.c          # Main program and argument parsing
├── paint.c         # Fractal calculation and rendering
├── event.c         # Event handling (keyboard, mouse)
├── inits.c         # Initialization functions
├── fractol.h       # Header file with structures and prototypes
├── libft/          # Custom C library
└── Makefile        # Build configuration
```

## Technical Details

- **Resolution**: 1000x800 pixels
- **Default Iterations**: 150
- **Zoom Factor**: 1.1x per scroll
- **Coordinate System**: Complex plane mapping


## License

This project is part of the 42 school curriculum.
