import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from matplotlib.patches import Rectangle
from matplotlib.collections import PatchCollection

with open('results.txt') as f:
    listoflists = [[float(x)/100 for x in line.split()] for line in f]

# listoflists = []
# listoflists.append((0, 0, 0.2, 0.4))
# listoflists.append((0, 0, 0.05, 0.10))


# build a rectangle in axes coords
xoffset, yoffset = 0.2, .3

width, height = 0.2, 0.4

fig, ax = plt.subplots()
patches = []

item = Rectangle((0 + xoffset, 0 + yoffset), .20, .40, angle=0.0, edgecolor="black", alpha = 0.4, fill = False)

ax.add_patch(item)

black = (0,0,0,1)

for somelist in listoflists:
    item=Rectangle((somelist[0] + xoffset, ((0.4-somelist[1]) + yoffset)), somelist[2], -somelist[3],angle=0.0, edgecolor="red")
    patches.append(item)

p = PatchCollection(patches, cmap=matplotlib.cm.jet, alpha=0.4, edgecolors=(black,))

colors = 100*np.random.rand(len(patches))
p.set_array(np.array(colors))

ax.add_collection(p)

plt.show()