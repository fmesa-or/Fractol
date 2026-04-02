<div align="center">

# Fractol

![Norminette](https://img.shields.io/badge/Norm-passing-brightgreen?style=flat-square) ![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white) ![Makefile](https://img.shields.io/badge/Makefile-427819?style=flat-square) ![macOS](https://img.shields.io/badge/macOS-000000?style=flat-square&logo=apple&logoColor=white) ![MLX42](https://img.shields.io/badge/MLX42-graphics-blue?style=flat-square) ![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square)

*An interactive fractal visualization tool in C using MLX42.*

</div>

---

## About the Project

Fractol is a real-time fractal explorer that renders beautiful mathematical fractals (Mandelbrot and Julia sets) with interactive controls. This project showcases skills in complex mathematics, graphics programming, and optimization at 42 School. Users can zoom, navigate, and explore the infinite complexity of fractals with smooth interactions and dynamic color palettes.

## Requirements

- Compiler: `gcc`
- Flags: `-Wall -Wextra -Werror`
- OS: macOS
- Standard: C99 or later
- Graphics Library: MLX42
- Build System: Make

## Installation and Usage

### Building

```bash
# Clone the repository
git clone https://github.com/usuario/fractol.git
cd fractol

# Compile the program
make

# Clean build artifacts
make clean

# Remove all generated files including the executable
make fclean

# Rebuild everything
make re
```

### Running the Program

```bash
# Display the Mandelbrot set
./fractol mandelbrot

# Display the Julia set (with optional parameters)
./fractol julia
```

### Usage Examples

```bash
# Explore the Mandelbrot set
./fractol mandelbrot

# Generate a Julia set with specific parameters
./fractol julia 0.286 0.01
./fractol julia -0.7 0.27015
```

## Supported Fractals

### Mandelbrot Set
- Classic fractal showing the self-similar boundary of the set
- Each pixel represents whether a point escapes to infinity
- Infinite complexity at the boundaries

### Julia Set
- A related fractal determined by a complex parameter
- Creates stunning, intricate patterns
- Parameter variations produce dramatically different sets
- Optional command-line parameters for specific Julia configurations

## Interactive Controls

### Keyboard Commands
- `ESC` - Close the window and exit program
- `ARROW KEYS` - Navigate/pan around the fractal
- `R` - Reset to initial view

### Mouse Commands
- **Scroll Up** - Zoom in (higher precision)
- **Scroll Down** - Zoom out (broader view)

## Implementation Details

### Architecture

**Core Components:**
- `init.c` - Initialization of window, data structures, and graphics
- `render.c` - Main rendering loop and fractal computation
- `color.c` - Color palette management and dynamic coloring
- `zoom.c` - Camera system and zoom functionality
- `error.c` - Error handling and input validation

**Fractal Sets:**
- `mandelbrot/` - Mandelbrot set implementation
- `julia/` - Julia set implementation with parameter support

**System:**
- `hooks/keys.c` - Keyboard event handling
- `hooks/scroll.c` - Mouse scroll event handling

### Algorithm Overview

1. **Point Mapping**: Convert screen coordinates to complex plane coordinates
2. **Iteration**: Calculate iterations for each point until it escapes (|z| > 2) or max iterations reached
3. **Color Mapping**: Map iteration count to color using dynamic palettes
4. **Rendering**: Display the pixel grid with calculated colors

### Performance Features

- Efficient iteration limit management
- Optimized color palette cycling
- Smooth zoom and pan animations
- Dynamic precision adjustment based on zoom level

## File Structure

```
fractol/
├── Makefile                 # Compilation rules
├── include/
│   ├── config.h            # Configuration macros
│   ├── fractol.h           # Main header with function declarations
│   └── structs.h           # Data structure definitions
├── lib/
│   ├── fr_printf/          # Custom printf implementation
│   ├── libft/              # 42 School utility library
│   └── MLX42/              # Graphics library (submodule)
├── src/
│   ├── main.c              # Program entry point
│   ├── hooks/              # Event handling
│   │   ├── keys.c
│   │   └── scroll.c
│   ├── sets/               # Fractal implementations
│   │   ├── mandelbrot/
│   │   └── julia/
│   └── utils/              # Utility functions
│       ├── color.c
│       ├── error.c
│       ├── init.c
│       ├── render.c
│       └── zoom.c
└── README.md               # This file
```

## Compilation Notes

- Static libraries are build from `libft/` and `lib/fr_printf/`
- MLX42 requires OpenGL and GLFW dependencies
- The implementation follows the 42 School Norm standards
- No external dependencies beyond the standard C library and graphics libraries

## Building Dependencies

### macOS
```bash
# Install required dependencies via Homebrew
brew install glfw3 glew cmake
```

### Linux (Ubuntu/Debian)
```bash
# Install required development packages
sudo apt-get install libglfw3-dev libglew-dev cmake libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxext-dev
```

## Testing and Exploration

### Recommended Explorations
```bash
# Start with the classic Mandelbrot set
./fractol mandelbrot

# Explore specific Julia sets
./fractol julia 0.286 0.01      # Spiral galaxy
./fractol julia -0.7 0.27015    # Complex structure
./fractol julia -0.4 0.6        # Fractal trees

# Use interactive controls:
# 1. Scroll to zoom into interesting areas
# 2. Use arrow keys to navigate
# 4. Adjust iterations with +/- for different detail levels
```

## Comparison with Standard Graphics Tools

Key features of Fractol:
- Interactive real-time rendering
- Custom mathematical implementation
- Optimized for educational purposes
- Smooth user experience with efficient rendering
- Personal color palette system
- Not suitable for production fractal exploration (use dedicated tools like Mandelbrot Set Explorer)

## Performance Considerations

- Rendering performance depends on:
  - Window resolution
  - Maximum iteration limit
  - Zoom level (deeper zoom = more computation)
  - Graphics hardware capabilities

- Optimization tips:
  - Reduce iteration count for faster rendering
  - Stay at moderate zoom levels for interactive exploration
  - Use valgrind for memory leak detection: `valgrind ./fractol mandelbrot`

## Memory Management

- Proper allocation and deallocation of graphics resources
- Memory is freed on program exit or error conditions
- No memory leaks with proper error handling

---

<div align="center">
Made with ☕ at <a href="https://42malaga.com">42 Málaga</a>
</div>
