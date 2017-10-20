import matplotlib.pyplot as plt
import matplotlib
from matplotlib.collections import PatchCollection
from matplotlib.patches import Rectangle

with open('results.txt') as f:
    listoflists = [[float(x)/100 for x in line.split()] for line in f]

# listoflists = []
# listoflists.append((0, 0, 0.2, 0.4))
# listoflists.append((0, 0, 0.05, 0.10))

# build a rectangle in axes coords
xoffset, yoffset = .4, .3

width, height = 0.2, 0.4

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

truck = patches.Rectangle(
    (0 + xoffset, 0 + yoffset), .20, .40,
    fill = False
    )

patches.append(truck)


for p in [
    Rectangle(
        (somelist[0] + xoffset, somelist[1] + yoffset), somelist[2], somelist[3],
        fill= False
    ) for somelist in listoflists
]:
    patches.append(p)

p = PatchCollection(patches, cmap=matplotlib.cm.jet, alpha=0.4)

colors = 100*np.random.rand(len(patches))
p.set_array(np.array(colors))

ax.add_collection(p)

plt.show()