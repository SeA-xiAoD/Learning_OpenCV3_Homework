# 10_1
[Code](./10_1)  
Don't know why I cannot find a function named cv::smooth(), so I use the cv::GaussianBlur to replace the cv::smoooth. (In fact, the cv::smooth() function is out of use) And the once 11 x 11 smoothing is more blur than twice 5 x 5 smoothing. I think this is because the pixel value of large area is more different than small area, so in order to be close to each pixel between large area, the smoothing value of large area will be more similar.
#

# 10_2
[Code](./10_2)  
They are very similar, almost same. The center of twice 5 x 5 smoothing is a little brighter than once 9 x 9 smoothing.
#

# 10_3
[Code](./10_3)  
The cv::smooth() function is out of use, so I made some similar exercises.
#

# 10_4
[Code](./10_4)  
The second function is used to smooth the edge of bright area, so the main effects come from the first function. And the difference is because the first erode function remain the min of local area rather the first dilate function remain the max of local area. So the erode() -> dilate() will have larger bright area than dilate() -> erode() that leads the image seem dirty.
#

# 10_5
[Code](./10_5)
#

# 10_6
[HDR algorithm](https://docs.opencv.org/3.0-beta/doc/tutorials/photo/hdr_imaging/hdr_imaging.html).
#

# 10_7
This exercise makes me confused. Based on my knowledge, if I need to know what part of the image is blue, I will need to use machine learning method to recognize sky of lake and then cut it out from the image. Beacuse if only use BGR pixel value, the B greater than some threshold (eg. 200) is not meaning for the pixel is blue (eg. [255, 255, 255] is white). So I am confused about this exercise. I'll be  appreciated if some one could give any idea about this question without machine learning method. Send me an E-mail. (^_^) 
#

# 10_8
I'll finish this exercise after chapter 12 (flood-fill).
#

# 10_9
After Ex_10_8.
#

# 10_10
[Code](./10_10)
#

# 10_11
[Code](./10_11)
#

# 10_12
[Code](./10_12)  
The size of two images are different, but the pixels are not obviously different. 
#

# 10_13
[Code](./10_13)
#

# 10_14
[Code](./10_14)
#

# 10_15
[Code](./10_15)
#

# 10_16
[Code](./10_16)  
Through the result of exercise c, we can konw that separable kernel and the order of the seperable kernel are not influence the filtering result.
#

# 10_17
[Code](./10_17)
#

# 10_18
[Code](./10_18)
#

# 10_19
[Code](./10_19)  
The results are changed. Because the kernel size is increasing, the bigger size influence more pixel so that the mag and angle of bigger kernel size have thicker line.
#
