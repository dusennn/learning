import numpy as np
import matplotlib.pyplot as plt
import matplotlib.tri as mtri


x_data = [1.0, 2.0, 4.0]
y_data = [2.0, 4.0, 6.0]

def forward(x):
    return x * w + b

def loss(x, y):
    y_pred = forward(x)
    return (y_pred - y) * (y_pred - y)

w_list = []
b_list = []
mes_list = []
for w in np.arange(0.0, 4.1, 0.1):
    print('w=', w)
    for b in np.arange(0.0, 4.1, 0.1):
        print('b=', b)
        l_sum = 0
        for x_val, y_val in zip(x_data, y_data):
            y_pred_val = forward(x_val)
            loss_val = loss(x_val, y_val)
            l_sum += loss_val
            print('\t', x_val, y_val, y_pred_val, loss_val)
        print('MSE=', l_sum / 3)
        w_list.append(w)
        b_list.append(b)
        mes_list.append(l_sum / 3)


# draw graph
fig = plt.figure(figsize=plt.figaspect(0.5))
ax = fig.add_subplot(111, projection='3d')
triang = mtri.Triangulation(w_list, mes_list)
ax.plot_trisurf(triang, b_list, cmap=plt.cm.CMRmap)
ax.set_zlim(-1, 1)

plt.show()
