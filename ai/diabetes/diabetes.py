import torch
import numpy as np
import matplotlib.pyplot as plt

'''
糖尿病分类预测
'''

'''Prepare dataset'''
xy = np.loadtxt('diabetes/dataset/diabetes.csv.gz', delimiter=',', dtype=np.float32)
x_data = torch.from_numpy(xy[:, :-1])
y_data = torch.from_numpy(xy[:, [-1]])

'''Design model'''
class DiabetesModel(torch.nn.Module):
    def __init__(self):
        super(DiabetesModel, self).__init__()
        self.linear1 = torch.nn.Linear(8, 6)
        self.linear2 = torch.nn.Linear(6, 4)
        self.linear3 = torch.nn.Linear(4, 2)
        self.linear4 = torch.nn.Linear(2, 1)
        self.activate = torch.nn.Softplus()

    def forward(self, x):
        x = self.activate(self.linear1(x))
        x = self.activate(self.linear2(x))
        x = self.activate(self.linear3(x))
        x = torch.nn.Sigmoid()(self.linear4(x))
        return x
model = DiabetesModel()

'''Construct loss and optimizer'''
criterion = torch.nn.BCELoss(size_average=False)
optimizer = torch.optim.AdamW(model.parameters(), lr=0.01)

'''Training cycle'''
loss_list = []
epochs = range(100000)
for epoch in epochs:
    y_pred = model(x_data)
    loss = criterion(y_pred, y_data)

    loss_list.append(loss.data)
    print('Epoch:%s, Loss:%s' % (epoch, loss.data, ))

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

'''Draw graph'''
plt.plot(epochs, loss_list)
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.show()
