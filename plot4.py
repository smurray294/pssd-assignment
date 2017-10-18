import matplotlib.pyplot as plt
import matplotlib.patches as patches

with open('results.txt') as f:
    listoflists = [[float(x) for x in line.split()] for line in f]

# listoflists = []
# listoflists.append((0, 0, 0.2, 0.4))
# listoflists.append((0, 0, 0.1, 0.2))


# build a rectangle in axes coords
xoffset, yoffset = .4, .3

width, height = 0.2, 0.4

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

for p in [
    patches.Rectangle(
        (somelist[0] + xoffset, somelist[1] + yoffset), somelist[2], somelist[3],
        fill=False
    ) for somelist in listoflists
]:
    ax.add_patch(p)

plt.show()