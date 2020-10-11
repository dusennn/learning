import os, sys
sys.path.append(os.getcwd())

import torch
import matplotlib.pyplot as plt

from datetime import datetime
from torchvision import (transforms, datasets, )
from torch.utils.data import (Dataset, DataLoader, )
from mnist.nn.nnet import NNet
from mnist.nn.cnnet import (CNNet, CNNet2, )
from mnist.nn.googlenet import (GoogLeNet, )
from mnist.nn.rsnet import (RSNet, )

class MnistModel(object):
    def __init__(self):
        '''Auto Choice GPU Or CPU'''
        self.device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')
        print('Using device:', self.device)
        '''Set Parallel '''
        torch.set_num_threads(8)
        torch.set_num_interop_threads(8)
        self.loss_list, self.epoch_list = [], []

    def run(self):
        self.__prepare_data()
        self.__build_net()
        self.__criterion_and_optimizer()

        for epoch in range(1, 10):
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
        # self.nnet = CNNet()
        # self.nnet = CNNet2()
        # self.nnet = GoogLeNet()
        self.nnet = RSNet()
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
                print('Epoch:%s, I:%s, Loss:%s, Time:%s' % (epoch, i, loss.item(), datetime.now()))

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
