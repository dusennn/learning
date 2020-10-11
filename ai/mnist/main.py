import torch
import matplotlib.pyplot as plt

from torchvision import (transforms, datasets, )
from torch.utils.data import (Dataset, DataLoader, )


class NNet(torch.nn.Module):
    def __init__(self):
        super(NNet, self).__init__()
        self.linear1 = torch.nn.Linear(784, 512)
        self.linear2 = torch.nn.Linear(512, 256)
        self.linear3 = torch.nn.Linear(256, 128)
        self.linear4 = torch.nn.Linear(128, 64)
        self.linear5 = torch.nn.Linear(64, 32)
        self.linear6 = torch.nn.Linear(32, 10)
        self.activate = torch.nn.ReLU()

    def forward(self, x):
        x = x.view(-1, 784)
        x = self.activate(self.linear1(x))
        x = self.activate(self.linear2(x))
        x = self.activate(self.linear3(x))
        x = self.activate(self.linear4(x))
        x = self.activate(self.linear5(x))
        return self.linear6(x)

class CNNet(torch.nn.Module):
    def __init__(self):
        super(CNNet, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, 10, kernel_size=5)
        self.conv2 = torch.nn.Conv2d(10, 20, kernel_size=5)
        self.pooling = torch.nn.MaxPool2d(2)
        self.fc = torch.nn.Linear(320, 10)
        self.relu = torch.nn.ReLU()
    
    def forward(self, x):
        batch_size = x.size(0)
        x = self.pooling(self.relu(self.conv1(x)))
        x = self.pooling(self.relu(self.conv2(x)))
        x = x.view(batch_size, -1)
        x = self.fc(x)
        return x


class MnistModel(object):
    def __init__(self):
        '''Auto Choice GPU Or CPU'''
        self.device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
        print('Using device:', self.device)
        self.loss_list, self.epoch_list = [], []

    def run(self):
        self.__prepare_data()
        self.__build_net()
        self.__criterion_and_optimizer()

        for epoch in range(1, 3):
            self.__train(epoch)
            self.__test(epoch)
        
        self.__show()

    def __prepare_data(self):
        batch_size = 64
        transform = transforms.Compose([
            transforms.ToTensor(),
            transforms.Normalize((0.1307,), (0.3081,)),
        ])

        self.train_dataset = datasets.MNIST(
            root='mnist/dataset/', train=True, download=True, transform=transform,
        )
        self.train_loader = DataLoader(dataset=self.train_dataset, shuffle=True, batch_size=batch_size)
        self.test_dataset = datasets.MNIST(
            root='mnist/dataset/', train=False, download=True, transform=transform,
        )
        self.test_loader = DataLoader(dataset=self.train_dataset, shuffle=False, batch_size=batch_size)
    
    def __build_net(self):
        # self.nnet = NNet()
        self.nnet = CNNet()
        self.nnet.to(self.device)

    def __criterion_and_optimizer(self):
        self.criterion = torch.nn.CrossEntropyLoss()
        self.optimizer = torch.optim.SGD(self.nnet.parameters(), lr=0.01, momentum=0.5)

    def __train(self, epoch):
        for i, (inputs, target) in enumerate(self.train_loader, 1):
            inputs, targets = inputs.to(self.device), target.to(self.device)

            self.optimizer.zero_grad()
            y_pred = self.nnet(inputs)
            loss = self.criterion(y_pred, target)
            loss.backward()
            if i % 100 == 0:
                self.loss_list.append(loss.data)
                self.epoch_list.append(self.epoch_list[-1]+1 if self.epoch_list else 1)
                print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item()))

            self.optimizer.step()

    def __test(self, epoch):
        correct = 0
        total = 0
        with torch.no_grad():
            for inputs, target in self.test_loader:
                inputs, target = inputs.to(self.device), target.to(self.device)

                outputs = self.nnet(inputs)
                _, predicted = torch.max(outputs.data, dim=1)
                total += target.size(0)
                correct += (predicted == target).sum().item()
        print('Accuracy on test set: %d %%' % (100 * correct / total) )

    def __show(self):
        plt.plot(self.epoch_list, self.loss_list)
        plt.xlabel('Epoch')
        plt.ylabel('Loss')
        plt.show()


if __name__ == "__main__":
    MnistModel().run()
