Contents of my folder:
1)A code file(task1.cpp)
2)A makefile
3)A readme file

aim:
This task is for anglecorrection and cropping of an image.

setup:

Compiling and running without using makefile
Step1: open terminal
step2: open the directory or folder in which your code is present on terminal
step3: compile the code using "$ g++ task1.cpp -o cam.o -pthread -std=c++11 `pkg-config --cflags --libs opencv`"
step4: run the code for image we need using "./cam.o image.jpg"
step5: An image named original image will open 
step6: select 4 points as following
	1)left up 
	2)left bottom 
	3)right bottom
	4)right up
step7: press enter
step8: An image named projected image will open after press enter
step9: An image named cropped image will open.
step10:those images and our project is done running.

Compiling and running using makefile
Step1: open terminal
step2: open the directory or folder in which your code is present on terminal
step3: compile the code using "$ make compile"
step4: run the code for image we need using "./cam.o image.jpg" or
	If you want to compile and run the code for empty image use "$ make empty"
	If you want to compile and run the code for traffic image use "$ make traffic"
step5: An image named original image will open.
step6: select 4 points as following
	1)left up 
	2)left bottom 
	3)right bottom
	4)right up
step7: press enter.
step8: An image named projected image will open after press enter.
step9: An image named cropped image will open.
step10:close those images and our project is done running.
