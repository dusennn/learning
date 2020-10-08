import torch
import numpy as np
import matplotlib.pyplot as plt

from torch.utils.data import (DataLoader, )
from torchvision import (transforms, datasets, )


class MnistModel(torch.nn.Module):
    def __init__(self):
        super(MnistModel, self).__init__()
        self.linear1 = torch.nn.Linear(28, 32)
        self.linear2 = torch.nn.Linear(32, 64)
        self.linear3 = torch.nn.Linear(64, 128)
        self.linear4 = torch.nn.Linear(128, 64)
        self.linear5 = torch.nn.Linear(64, 32)
        self.linear6 = torch.nn.Linear(32, 16)
        self.linear7 = torch.nn.Linear(16, 1)
        self.activate = torch.nn.ReLU()

    def forward(self, x):
        x = self.activate(self.linear1(x))
        x = self.activate(self.linear2(x))
        x = self.activate(self.linear3(x))
        x = self.activate(self.linear4(x))
        x = self.activate(self.linear5(x))
        x = self.activate(self.linear6(x))
        x = torch.nn.Sigmoid()(self.linear7(x))
        return x


def main():
    train_dataset = datasets.MNIST(root='examples/.dataset/mnist',
                                    train=True,
                                    transform=transforms.ToTensor(),
                                    download=True)
    test_dataset = datasets.MNIST(root='examples/.dataset/mnist',
                                    train=False,
                                    transform=transforms.ToTensor(),
                                    download=True)
    train_loader = DataLoader(dataset=train_dataset, batch_size=32, shuffle=True)
    test_loader = DataLoader(dataset=test_dataset, batch_size=32, shuffle=False)

    model = MnistModel()

    criterion = torch.nn.BCELoss(size_average=False)
    optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

    loss_list = []
    epoch_list = []
    for epoch in range(100):
        for batch_idx, (inputs, target) in enumerate(train_loader, 0):
            #1. Forward
            y_pred = model(inputs)
            loss = criterion(y_pred, target)
            loss_list.append(loss.data)
            epoch_list.append(epoch * i)
            print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item()))
            #2. Backward
            optimizer.zero_grad()
            loss.backward()
            #3. Update
            loss.step()

    plt.plot(epoch_list, loss_list)
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.show()


if __name__ == "__main__":
    main()
