# 12_1
Obviously, if the high threshold is larger, the edges will be more clear, of course because the large gradients are less than small ones. The difference between high:low threshold setting is not remarkable, unless you set the low threshold to a very low level.
#

# 12_2
[Code](./12_2)  
#

# 12_3
Can I consider any kind of shape as a construction of multiple lines? If so, maybe hough transformation can detect the lines. and we can accumulate the length of the lines as perimeter of the shape.
#

# 12_4
[Code](./12_4)  
#

# 12_5
[Code](./12_5)  
Can detect some edges between white and black.
#

# 12_6
[Code](./4_2)  
Same as Ex_4_2_e.
#

# 12_7
Maybe first step is doing thresh_binary of two shapes. And next step is using distance transform to find the center of each shape which is the pixel of biggest value. And then put the center to same point.
#

# 12_8
[Code](./12_8)  
NOT FINISH. I cannot totaly understand DFT and how to use it. I'll complete it soon.
#

# 12_9
[Code](./12_9)  
#

# 12_10
[Code](./12_10)  
#

# 12_11
[Code](./12_11)  
#

# 12_12
The watershed algorithm is based on seed, so I think if there is a curve in front of the car and the inverted "U" mask is out of range, the segmentation might wrong. Or if some barriers on the road have same colors as the road, that is confused using this algorithm and is very dangerous.   
#