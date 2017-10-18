import matplotlib.pyplot as plt
import matplotlib.patches as patches

# build a rectangle in axes coords
xoffset, yoffset = .4, .3

left, width = 0+xoffset, .2
bottom, height = 0+yoffset, .4
right = left + width
top = bottom + height

fig = plt.figure()
ax = fig.add_axes([0,0,1,1])

# axes coordinates are 0,0 is bottom left and 1,1 is upper right
p = patches.Rectangle(
    (left, bottom), width, height,
    fill=False, transform=ax.transAxes, clip_on=False
    )

ax.add_patch(p)
plt.show()