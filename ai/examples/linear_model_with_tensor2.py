import torch
import matplotlib.pyplot as plt


x_data = [1.0, 2.0, 3.0]
y_data = [2.0, 4.0, 6.0]

learning_rate = 0.001

w1 = torch.Tensor([1.0])
w1.requires_grad = True
w2 = torch.Tensor([1.0])
w2.requires_grad = True
b = torch.Tensor([1.0])
b.requires_grad = True

def forward(x):
    return w1 * x**2 + w2 * x + b

def loss(x, y):
    y_pred = forward(x)
    return (y_pred - y) ** 2

print('Predict (before training)', 4, forward(4).item())
loss_list = []
epoch_list = []
for epoch in range(100):
    for x, y in zip(x_data, y_data):
        l = loss(x, y)
        l.backward()
        print('\tgrad:', x, y, w1.grad.item(), w2.grad.item())
        w1.data = w1.data - learning_rate * w1.grad.data
        w2.data = w2.data - learning_rate * w2.grad.data
        b.data = b.data - learning_rate * b.grad.data
        
        w1.grad.data.zero_()
        w2.grad.data.zero_()
        b.grad.data.zero_()
        
        loss_list.append(l.data)
        epoch_list.append(epoch)
        print('Progress:', epoch, l.item())
print('Predict (after training)', 4, forward(4).item())


plt.plot(epoch_list, loss_list)
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.show()
