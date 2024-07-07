"""plot xy data"""
import numpy as np
import matplotlib.pyplot as plt

xy_data = np.loadtxt("../xy_data.dat")
plt.plot(xy_data[:, 0], xy_data[:, 1], '.', markersize=10)
plt.show()
