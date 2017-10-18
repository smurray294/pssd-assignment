import matplotlib.pyplot as plt

#rectangle = [(0,0),(0,1),(1,1),(1,0)]
hexagon = [(0,0),(0,1),(1,2),(2,1),(2,0),(1,-1),(0,0)]
#l_shape = [(0,0),(0,3),(1,3),(1,1),(3,1),(3,0)]
#concave = [(0,0),(0,3),(1,3),(1,1),(2,1),(2,3),(3,3),(3,0)]

#for points in [rectangle, hexagon, l_shape, concave]:
for points in [hexagon]:
    # 1. Can I get rid of the zip? plot directly by points 
    # 2. How can I make the shape complete?
    xs, ys = zip(*points)
    plt.plot(xs, ys, 'o')
    plt.plot(xs, ys, '-')

    automin, automax = plt.xlim()
    plt.xlim(automin-0.5, automax+0.5)
    automin, automax = plt.ylim()
    plt.ylim(automin-0.5, automax+0.5)
    # Can I display the shapes 2 in 1 line?
    plt.show()