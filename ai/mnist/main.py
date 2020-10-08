import torch
import torch.functional as F

from torchvision import (transforms, datasets, )
from torch.utils.data import (Dataset, DataLoader, )


class Net(torch.nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.linear1 = torch.nn.Linear(784, 512)
        self.linear2 = torch.nn.Linear(512, 256)
        self.linear3 = torch.nn.Linear(256, 128)
        self.linear4 = torch.nn.Linear(128, 64)
        self.linear5 = torch.nn.Linear(64, 32)
        self.linear6 = torch.nn.Linear(32, 10)

    def forward(self, x):
        x = x.view(-1, 784)
        x = torch.nn.ReLU()(self.linear1(x))
        x = torch.nn.ReLU()(self.linear2(x))
        x = torch.nn.ReLU()(self.linear3(x))
        x = torch.nn.ReLU()(self.linear4(x))
        x = torch.nn.ReLU()(self.linear5(x))
        return self.linear6(x)


class MnistModel(object):
    def run(self):
        self.__prepare_data()
        self.__build_net()
        self.__criterion_and_optimizer()

        for epoch in range(100):
            self.__train(epoch)
            self.__test(epoch)

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
        self.net = Net()

    def __criterion_and_optimizer(self):
        self.criterion = torch.nn.CrossEntropyLoss()
        self.optimizer = torch.optim.SGD(self.net.parameters(), lr=0.01, momentum=0.5)

    def __train(self, epoch):
        for i, (inputs, labels) in enumerate(self.train_loader, 0):
            self.optimizer.zero_grad()

            y_pred = self.net(inputs)

            loss = self.criterion(y_pred, labels)
            loss.backward()

            if i % 300 == 0:
                print('Epoch:%s, I:%s, Loss:%s' % (epoch, i, loss.item()))

            self.optimizer.step()

    def __test(self, epoch):
        correct = 0
        total = 0
        with torch.no_grad():
            for images, labels in self.test_loader:
                outputs = self.net(images)
                _, predicted = torch.max(outputs.data, dim=1)
                total += labels.size(0)
                correct += (predicted == labels).sum().item()
        print('Accuracy on test set: %d %%' % (100 * correct / total) )

if __name__ == "__main__":
    MnistModel().run()
