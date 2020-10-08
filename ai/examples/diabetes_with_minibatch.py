import torch
import numpy as np
import matplotlib.pyplot as plt

from torch.utils.data import (Dataset, DataLoader, )


class DiabetesDateset(Dataset):
    def __init__(self, filepath):
        xy = np.loadtxt(filepath, delimiter=',', dtype=np.float32)
        self.len = xy.shape[0]
        self.x_data = torch.from_numpy(xy[:, :-1])
        self.y_data = torch.from_numpy(xy[:, [-1]])

    def __getitem__(self, index):
        return self.x_data[index], self.y_data[index]

    def __len__(self):
        return self.len

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


def main():
    '''Step1: Prepare dataset'''
    dataset = DiabetesDateset('examples/dataset/diabetes.csv.gz')
    train_loader = DataLoader(dataset=dataset, 
                            batch_size=32, 
                            shuffle=True,
                            num_workers=2)

    '''Step2: Design model'''
    model = DiabetesModel()

    '''Step3: Construct loss and optimizer'''
    criterion = torch.nn.BCELoss(size_average=False)
    optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

    '''Step4: Training cycle'''
    loss_list = []
    epoch_list = []
    for epoch in range(10):
        for i, (inputs, labels) in enumerate(train_loader, 0):
            #1. Forward
            y_pred = model(inputs)
            loss = criterion(y_pred, labels)
            loss_list.append(loss.data)
            epoch_list.append(epoch * i)
            print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item()))
            #2. Backward
            optimizer.zero_grad()
            loss.backward()
            #3. Update
            optimizer.step()

    '''Step5: Draw graph'''
    plt.plot(epoch_list, loss_list)
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.show()

if __name__ == "__main__":
    main()
