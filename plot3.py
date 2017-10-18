import matplotlib.pyplot as plt
import matplotlib.patches as patches

# build a rectangle in axes coords
xoffset, yoffset = .4, .3

width, height = 0.2, 0.4

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

for p in [
    patches.Rectangle(
        (0 + xoffset, 0 + yoffset), width, height,
        fill=False
    ),
    patches.Rectangle(
        (0 + xoffset, 0 + yoffset), 0.1, 0.2,
        fill=False
    ),
]:
    ax.add_patch(p)

plt.show()