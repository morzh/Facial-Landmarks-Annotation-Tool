# FLAT - Facial Landmarks Annotation Tool

A visual editor for manually annotating facial landmarks in images of human faces.

![Screenshot1](Screenshot%20from%202020-03-05%2017-28-26.png)
![Screenshot2](Screenshot%20from%202020-03-05%2017-42-53.png)

## Usage

Create a new face annotation dataset (files with extension `.fad`) and add the face images. Then, add the facial features and connect then as desired using either the program menus or the context menu. The zoom level can be controlled either from the widget control on the image properties tool window or by holding CTRL and scrolling the mouse wheel. While zoomed, an image can also be side scrolled by holding SHIFT and scrolling the mouse wheel, to rotate image use ALT. To change facial landmarks radius use ALT+CTRL. All images in the same face annotation dataset share the same model, that is they have the same amount of face landmarks (even though they can be differently positioned for each image).

## Dependences

The application has been developed and tested with:

- [CMake](https://cmake.org/) 3.5.0-rc3
- [Qt](http://www.qt.io/) 5.5.1 32-bit

## Building

1. Use CMake to configure and generate the environment. I suggest using the folder `build`, since it is the one ignored by gitignore.
2. In Windows, open the Visual Studio solution and build with the desired build type (*debug*, *release*, etc).
3. In Linux, use type `make` to let the Makefile produce the binary in the build type configured by CMake.
4. The code produces only a single executable named `flat(.exe)`, that depends only on Qt. If you want to use the "Fit Landmarks" option mentioned before, go to the CSIRO Face Analysis SDK page, download and build its libraries and executables. Then, configure in FLAT the path for the `face-fit(.exe)` executable.

## Credits

Copyright (C) 2016 [Luiz Carlos Vieira](http://www.luiz.vieira.nom.br). Available under GPL (see details in the license file).

The application icons and images are either from or based on the Oxygen Icons Set, downloaded as [PNGs from Felipe Azevedo (pasnox)](https://github.com/pasnox/oxygen-icons-png) and [licensed under LGPL from KDE](https://techbase.kde.org/Projects/Oxygen/Licensing), and the [Farm-Fresh Web Icons Set](http://www.fatcow.com/free-icons), licensed under [Creative Commons (CC BY 4.0)](http://creativecommons.org/licenses/by/4.0/).
