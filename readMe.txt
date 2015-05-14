# Fista fdct3d
Reconstruction package using FISTA and 3D Curvelet transformation
Developed and modified by: Mafijul Bhuiyan

About
=====

FISTA_FDCT3D is a C++ program which can reconstruct 3D data applying Fast iterative soft thresholding algorithm (FISTA).
Reconstruction is based on 3D curvelet transformation. 3D curvelet transformation is written by Lexing Ying 
and later on modified by Mafijul Bhuiyan to solve memory leaking and FFTW problem.


Installing
==========

Required packages: 
 1. FFTW 3.3.0 or higher
 2. g++
 
Installation of FISTA_FDCT3D is a very straightforward process. Just copy the whole software package in your machine
and run make all command in your terminal. 

Make sure the path of FFTW plug-in id correct. 


Running
=======
Before running, check the input parameters in input.txt file. Input.txt file contains the dimensions of 3D curvelet  
transformation. 

1. cd Debug
2. make clean 
3. make all 
4. ./fdct3d 


That's all. 

Please contact: mbhuiyan@ualberta.ca
