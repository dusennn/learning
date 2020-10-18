import torch


class Net(torch.nn.Module):
    def __init__(self, input_size, hidden_size, batch_size):
        super(Net, self).__init__()
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.batch_size = batch_size

        self.cell = torch.nn.RNNCell(input_size, hidden_size)

    def forward(self, _input, hidden):
        return self.cell(_input, hidden)

    def init_hidden(self):
        return torch.zeros(self.batch_size, self.hidden_size)


def main():
    input_size = 4
    hidden_size = 4
    batch_size = 1

    idx2char = ['h', 'e', 'l', 'o']
    x_data = [0, 1, 2, 2, 3] # hello
    y_data = [3, 0, 2, 3, 2] # ohlol

    one_hot_lookup = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1],
    ]
    x_one_hot = [one_hot_lookup[x] for x in x_data]

    inputs = torch.Tensor(x_one_hot).view(-1, batch_size, input_size)
    labels = torch.LongTensor(y_data).view(-1, 1)

    net = Net(input_size, hidden_size, batch_size)

    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(net.parameters(), lr=0.01)

    for epoch in range(100):
        loss = 0
        criterion.zero_grad()
        hidden = net.init_hidden()
        print('Predicted string: ', end='')
        for _input, label in zip(inputs, labels):
            hidden = net(_input, hidden)
            loss += criterion(hidden, label)
            _, idx = hidden.max(dim=1)
            print(idx2char[idx.item()], end='')
        loss.backward()
        optimizer.step()
        print(', Epoch[%d/15] loss=%.4f' % (epoch + 1, loss.item()))


if __name__ == "__main__":
    main()
