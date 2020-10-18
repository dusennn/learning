import torch


class Net(torch.nn.Module):
    def __init__(
        self, input_size, hidden_size, embding_size, batch_size, num_layers, num_class
    ):
        super(Net, self).__init__()
        self.hidden_size = hidden_size
        self.num_layers = num_layers
        self.num_class = num_class
        self.embding = torch.nn.Embedding(input_size, embding_size)
        self.rnn = torch.nn.GRU(embding_size, hidden_size, num_layers, batch_first=True)
        self.fc = torch.nn.Linear(hidden_size, num_class)

    def forward(self, x):
        hidden = torch.zeros(self.num_layers, x.size(0), self.hidden_size)
        x = self.embding(x)
        x, _ = self.rnn(x, hidden)
        x = self.fc(x)
        return x.view(-1, self.num_class)


def main():
    input_size = 4
    hidden_size = 8
    embding_size = 10
    batch_size = 1
    num_layers = 2
    num_class = 4
    seq_len = 5

    idx2char = ['h', 'e', 'l', 'o']
    x_data = [[0, 1, 2, 2, 3]] #hello
    y_data = [3, 0, 2, 3, 2] #ohlol

    inputs = torch.LongTensor(x_data)
    labels = torch.LongTensor(y_data)

    net = Net(input_size, hidden_size, embding_size, batch_size, num_layers, num_class)

    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(net.parameters(), lr=0.01)

    epoch_num = 100
    for epoch in range(epoch_num):
        optimizer.zero_grad()

        outputs = net(inputs)
        loss = criterion(outputs, labels)
        loss.backward()

        optimizer.step()

        _, idx = outputs.max(dim=1)
        idx = idx.data.numpy()
        predict_str = ''.join([idx2char[i] for i in idx])
        print('Epoch[%d/%d] Predict:%s, Loss:%.3f' % (epoch+1, epoch_num, predict_str, loss.item()))
        
if __name__ == "__main__":
    main()
