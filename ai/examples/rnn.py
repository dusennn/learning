import torch


class Net(torch.nn.Module):
    def __init__(self, input_size, hidden_size, batch_size, num_layers):
        super(Net, self).__init__()
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.batch_size = batch_size
        self.num_layers = num_layers

        self.rnn = torch.nn.RNN(input_size, hidden_size, num_layers)

    def forward(self, _input):
        hidden = torch.zeros(self.num_layers, self.batch_size, self.hidden_size)
        out, _ = self.rnn(_input, hidden)
        return out.view(-1, self.hidden_size)


def main():
    idx2char = ['h', 'e', 'l', 'o']
    x_data = [0, 1, 2, 2, 3] #hello
    y_data = [3, 0, 2, 3, 2] #ohlol

    one_hot_lookup = [
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1],
    ]
    x_one_hot = [one_hot_lookup[x] for x in x_data]

    input_size = 4
    hidden_size = 4
    batch_size = 1
    num_layers = 1
    seq_len = 5
    inputs = torch.Tensor(x_one_hot).view(seq_len, batch_size, input_size)
    labels = torch.LongTensor(y_data)

    net = Net(input_size, hidden_size, batch_size, num_layers)

    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(net.parameters(), lr=0.01)

    epoch_num = 1000
    for epoch in range(epoch_num):
        optimizer.zero_grad()
        outputs = net(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        _, idx = outputs.max(dim=1)
        idx = idx.data.numpy()
        print('Predicted: ', ''.join([idx2char[x] for x in idx]), end=',')
        print(', Epoch[%d/%d] loss = %.3f' % (epoch+1, epoch_num,  loss.item()))


if __name__ == "__main__":
    main()
