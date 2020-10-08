import torch
import matplotlib.pyplot as plt

''' Step1: Prapare dataset '''
x_data = torch.Tensor([[1.0], [2.0], [3.0]])
y_data = torch.Tensor([[2.0], [4.0], [6.0]])

''' Step2: Design model using Class '''
class LinearModel(torch.nn.Module):
    def __init__(self):
        super(LinearModel, self).__init__()
        self.linear = torch.nn.Linear(1, 1)

    def forward(self, x):
        y_pred = self.linear(x)
        return y_pred
model = LinearModel()

''' Step3: Construct loss and optimizer '''
criterion = torch.nn.MSELoss(size_average=False)
# optimizer = torch.optim.SGD(model.parameters(), lr=0.01)
# optimizer = torch.optim.Adagrad(model.parameters(), lr=0.01)
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)
# optimizer = torch.optim.ASGD(model.parameters(), lr=0.01)
# optimizer = torch.optim.RMSprop(model.parameters(), lr=0.01)
# optimizer = torch.optim.Rprop(model.parameters(), lr=0.01)

''' Step4: Trainin cycle '''
loss_list = []
epochs = range(1000)
for epoch in epochs:
    y_pred = model(x_data)
    loss = criterion(y_pred, y_data)

    loss_list.append(loss.data)
    print("Epoch:%s, Loss:%s" % (epoch, loss,))

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

''' Step5: Draw graph '''
plt.plot(epochs, loss_list)
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.show()
