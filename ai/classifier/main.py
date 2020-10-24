import time
import torch

from torch.utils.data import (DataLoader, )
from dataset import (NameDataset, )
from gru import (Net, )
from root import (time_since, evaluation, create_tensor, make_tensors, )


class NameClassifier:
    def __init__(self):
        self.hidden_size = 100
        self.batch_size = 256
        self.num_layer = 2
        self.num_epochs = 100
        self.num_chars = 128
        self.use_gpu = False

    def run(self):
        self.train_set = NameDataset(is_train_set=True)
        self.train_loader = DataLoader(self.train_set, batch_size=self.batch_size, shuffle=True)
        self.test_set = NameDataset(is_train_set=False)
        self.test_loader = DataLoader(self.test_set, batch_size=self.batch_size, shuffle=True)
        num_country = self.train_set.get_country_num()

        self.net = Net(self.num_chars, self.hidden_size, num_country, self.num_layer, True, False)
        if self.use_gpu:
            device = torch.device("cude:0")
            self.net.to(device)
        
        self.criterion = torch.nn.CrossEntropyLoss()
        self.optimizer = torch.optim.Adam(self.net.parameters(), lr=0.01)

        print("Training for %d epochs..." % self.num_epochs)
        acc_list = []
        for epoch in range(1, self.num_epochs+1):
            self.start = time.time()
            self._train_model(epoch)
            acc = self._test_model()
            acc_list.append(acc)

    def _train_model(self, epoch):
        total_loss = 0
        for i, (names, countries) in enumerate(self.train_loader, 1):
            inputs, seq_lengths, target = make_tensors(names, countries, self.use_gpu)
            output = self.net(inputs, seq_lengths)
            loss = self.criterion(output, target)
            self.optimizer.zero_grad()
            loss.backward()
            self.optimizer.step()

            total_loss += loss.item()
            if i % 10 == 0:
                print('{} Epoch:{} [{}/{}] loss={}'.format(
                    time_since(self.start), epoch, i * len(inputs), len(self.train_set),
                    total_loss / (i * len(inputs))
                ))
        return total_loss

    def _test_model(self):
        correct = 0
        total = len(self.test_set)
        print('Evaluating trained model...')
        with torch.no_grad():
            for i, (names, countries) in enumerate(self.test_loader, 1):
                inputs, seq_lengths, target = make_tensors(names, countries, self.use_gpu)
                output = self.net(inputs, seq_lengths)
                pred = output.max(dim=1, keepdim=True)[1]
                correct += pred.eq(target.view_as(pred)).sum().item()
            
            percent = '%.2f' % (100 * correct / total)
            print('Test set: Accuracy {}/{} {}%'.format(correct, total, percent))
        return correct / total


if __name__ == "__main__":
    NameClassifier().run()
