This is a simple demo for 3D Object Modeling based on an RGB-D camera 

General Notes
-------------------------
This package is designed to use RGB-D images for 3D object reconstruction. 

If you use this code for your reasearch, please cite the following papers:
```
[1] J. Xie, Y.F. Hsu, R. Feris, M.T. Sun, 
"Fine registration of 3D point clouds fusing structural and photometric information using an RGB-D camera," 
Journal of Visual Communication and Image Representation (JVCI), vol. 32, pp. 194-204, Oct. 2015.

[2] M. Jaiswal, J. Xie and M.T. Sun, 
"3D Object Modeling with a Kinect Camera," 
Asia-Pacific Signal and Information Processing Association Annual Summit and Conference (APSIPA ASC) 2014.
```
[This](https://sites.google.com/site/junxie302/code-sample-for-object-modeling-with-an-rgbd-images) webpage show a few demo of the sample code. 

Building Environment
-------------------------
Building requires CMake, OpenCV, and [PCL](http://pointclouds.org/downloads/) cross platform toolkit. The recommended OpenCV version is 3.4.x and the recommended PCL version is 1.7. The program has been tested to successfully build on Ubuntu 18.04, OpenCV 3.4.10, PCL 1.7.1 installed. 

<details>
<summary>Install OpenCV > 3.4.2: </summary>
`opencv_contrib` is required to be installed together with OepnCV.

Download [OpenCV](https://opencv.org/releases/). We recommend 3.4.10.

Download [opencv_contrib](https://github.com/opencv/opencv_contrib/releases). The version should be the same with OpenCV.

Unzip the two files, and put the folder `opencv_contrib-3.4.x` in the folder `opencv-3.4.x`.

```Linux
cd opencv-3.4.x
mkdir build
cd build/
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib-3.4.10/modules -D OPENCV_ENABLE_NONFREE=true ..
# the flag OPENCV_ENABLE_NONFREE  should be set to true for OpenCV > 3.4.2 for patent reasons
sudo make
sudo make install
```
</details>

To build the code
```
mkdir build
cd build
cmake ..
make
```
If there are no erros, a binary called reconstruct will be built. 

How to Run
------------------------
```
$reconstruct -[dir of txt file for the input image names]  [options]
```

Options:
```
-r   <threhold_r>       adjust registration threshold (DEFAULT=0.0035f)
-h                      this help
-g                      global Alignment
-lcoff                  turn off loop detection switch (DEFAULT=1)
-m                      moving least square surface smoothing
-dn                     de-noising (statistic outlier removal)
-vd  <threshold_vd>     voxel down sampling (DEFAULT=0.002f)
-iter <# of iterations> global alignment iterations (DEFAULT=3)
-hessian <threshold_h>  SIFT matching threshold (DEFAULT=200f), lower-> more matches
```

The txt file will point to a directory and list the image names used for reconstruction
Format of the txt file for the input image names should be:

```
dir/frame1
dir/frame2
...
dir/frame N (without format extension)
```

For each image name, it should point to four files with the following names:
```
Depth image:     framex_depth.png 
RGB image:       framex_rgb.png 
Mask image:      framex_mask.png    #pre-Segmentated mask, segmentation is not included in the source code
Location file:   framex_loc.txt     #(optional) cropping location indication if the image is cropped
```


An exmaple command is   
```
$reconstruct ../resources/ -g -dn -vd 0.001 -m
```
A few of [RGB-D data](http://rgbd-dataset.cs.washington.edu/) has been provided in resources/ in order to run the demo.




----------
Please feel free to contact xjsjtu88@gmail.com for any questions or bug reports. 
