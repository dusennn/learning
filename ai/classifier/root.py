import time
import matplotlib.pyplot as plt


def time_since(since):
    s = time.time() - since
    m = math.floor(s / 60)
    s -= m * 60
    return '%dm %ds' % (m, s)


def evaluation(acc_list):
    x = list(range(acc_list))
    y = acc_list
    plt.plot(x, y)
    plt.xlabel('Epoch')
    plt.ylabel('Accuracy')
    plt.grid()
    plt.show()
