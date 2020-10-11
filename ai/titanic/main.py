import torch 
import pandas as pd

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
        self.x_data = torch.tensor(xy[['Pclass','Sex','Age','SibSp','Parch','Fare','Embarked']].values,
            dtype=torch.float32
        )
        self.y_data = torch.tensor(xy['Survived'].values, dtype=torch.float32)
     
    def __getitem__(self, index):
        return self.x_data[index], self.y_data[index]

    def __len__(self):
        return self.len


class Net(torch.nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.linear1 = torch.nn.Linear(7, 16)
        self.linear2 = torch.nn.Linear(16, 8)
        self.linear3 = torch.nn.Linear(8, 4)
        self.linear4 = torch.nn.Linear(4, 1)
        self.activate = torch.nn.ReLU()

    def forward(self, x):
        x = self.activate(self.linear1(x))
        x = self.activate(self.linear2(x))
        x = self.activate(self.linear3(x))
        return torch.nn.Sigmoid()(self.linear4(x))

class TitanicModel(object):
    def run(self):
        self.__prepare_data()
        self.__build_net()
        self.__criterion_and_optimizer()

        for epoch in range(100):
            self.__train(epoch)
            # self.__test(epoch)

    def __prepare_data(self):
        self.train_dataset = TitanicDataset('titanic/dataset/train.csv')
        self.train_loader = DataLoader(dataset=self.train_dataset, shuffle=True, batch_size=42)
        # self.test_dataset = TitanicDataset('titanic/dataset/test.csv')
        # self.test_loader = DataLoader(dataset=self.test_dataset, shuffle=False, batch_size=42)
    
    def __build_net(self):
        self.net = Net()

    def __criterion_and_optimizer(self):
        self.criterion = torch.nn.BCELoss()
        self.optimizer = torch.optim.SGD(self.net.parameters(), lr=0.01, momentum=0.5)

    def __train(self, epoch):
        for i, (inputs, labels) in enumerate(self.train_dataset, 0):
            self.optimizer.zero_grad()

            y_pred = self.net(inputs)

            loss =  self.criterion(y_pred, labels)
            loss.backward()
            if i % 300 == 0:
                print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item()))

            self.optimizer.step()
        
    def __test(self, epoch):
        correct = 0
        total = 0
        with torch.no_grad():
            for inputs, labels in self.test_loader:
                outputs = self.net(inputs)
                _, predicted = torch.max(outputs.data, dim=1)
                total += labels.size(0)
                correct += (predicted == labels).sum().item()
        print('Accuracy on test set: %d %%' % (100 * correct / total))


if __name__ == "__main__":
    TitanicModel().run()
