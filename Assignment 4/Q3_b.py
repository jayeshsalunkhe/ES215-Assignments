import matplotlib.pyplot as plt
import numpy as np

# x-coordinates of left sides of bars
left = [1, 2, 3, 4, 5,6]

# heights of bars
height3 = [0.84184, 0.48090,0.85797,  0.93559, 0.48135, 0.92849 ]
height2 = [0.09837, 0.07124, 0.10135, 0.11096, 0.07095, 0.10971]
height1 = [0.01144, 0.00720, 0.01548, 0.01395, 0.01628, 0.00805]

# labels for bars
tick_label = ['ijk', 'ikj', 'jik', 'jki', 'kij', 'kji']

# Set position of bar on X axis
barWidth = 0.25
fig = plt.subplots(figsize =(12, 8))
br1 = np.arange(len(height1))
br2 = [x + barWidth for x in br1]
br3 = [x + barWidth for x in br2]

# plotting a bar chart



plt.bar(br1, height1, color ='r', width = barWidth,
        edgecolor ='grey', label ='128')
plt.bar(br2, height2, color ='g', width = barWidth,
        edgecolor ='grey', label ='256')
plt.bar(br3, height3, color ='b', width = barWidth,
        edgecolor ='grey', label ='512')

# naming the x-axis
plt.xlabel('Loop Iterations')
# naming the y-axis
plt.ylabel('time in secs')
# plot title
plt.title('Comparision Between N')

# function to show the plot
plt.legend()
plt.show()