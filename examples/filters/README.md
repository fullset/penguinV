# How to compile    
- Microsoft Visual Studio    
Open example_filters.vcxproj file in this directory to create solution for your Visual Studio version. Remember that minimum version of VS for this example is 2010.

- g++    
In this directory you need to type/paste this text in terminal:    
	```bash
	g++ -std=c++11 -Wall example_filters.cpp ../../src/image_function_helper.cpp ../../src/image_function.cpp ../../src/filtering.cpp ../../src/FileOperation/bitmap.cpp -o application
	```

- make    
In this directory you need to type/paste this text in terminal:    
	```bash
	make ./example_filters
	```