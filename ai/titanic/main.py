import torch
import pandas as pd
import matplotlib.pyplot as plt

from torch.utils.data import (Dataset, DataLoader, )


class TitanicDataset(Dataset):
    def __init__(self, filepath):
        super(TitanicDataset, self).__init__()
        xy = pd.read_csv(filepath, 
            sep=',', 
            encoding='latin-1', 
            engine='python',
            usecols=['Survived','Pclass','Sex','Age','SibSp','Parch','Fare','Embarked'],
            converters={
                'Sex':lambda x: -1 if str(x) == 'female' else 1, 
                'Embarked':lambda x: 1 if str(x) == 'C' else 2 if str(x) == 'Q' else 3,
            },
        )
        xy['Age'].fillna(xy['Age'].mean(), inplace=True)
        self.len = xy.shape[0]
        self.x_data = torch.tensor(xy['Survived'].values)
        self.y_data = torch.tensor(xy[['Pclass','Sex','Age','SibSp','Parch','Fare','Embarked']].values, 
            dtype=torch.float32
        )

    def __getitems__(self, index):
        return self.x_data[index], self.y_data[index]

    def __len__(self):
        return self.len


class TitanicModel(torch.nn.Module):
    def __init__(self):
        super(TitanicModel, self).__init__()
        self.linear1 = torch.nn.Linear(11, 9)
        self.linear2 = torch.nn.Linear(9, 6)
        self.linear3 = torch.nn.Linear(6, 3)
        self.linear4 = torch.nn.Linear(3, 1)
        self.activate = torch.nn.ReLU()

    def forward(self, x):
        x = self.activate(self.linear1(x))
        x = self.activate(self.linear2(x))
        x = self.activate(self.linear3(x))
        x = torch.nn.Sigmoid(self.linear4(x))
        return x


def run():
    dataset = TitanicDataset('titanic/dataset/train.csv')
    data_loader = DataLoader(dataset=dataset, batch_size=32, shuffle=True, num_workers=2)

    model = TitanicModel()

    criterion = torch.nn.BCELoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

    loss_list = []
    epoch_list = []
    for epoch in range(100):
        for i, (inputs, labels) in enumerate(data_loader, 0):
            #1.Forward
            y_pred = model(inputs)
            loss = criterion(y_pred, labels)
            loss_list.append(loss.data)
            epoch_list.append(epoch * i)
            print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item(),))
            #2.Backward
            optimizer.zero_grad()
            loss.backward()
            #3.Update
            optimizer.step()

    
    plt.plot(epoch_list, loss_list)
    plt.xlabel('Epoch')
    plt.ylabel('Loss')


if __name__ == "__main__":
    run()
