import torch


def main():
    batch_size = 1
    seq_len = 3
    input_size = 4
    hidden_size = 2

    cell = torch.nn.RNNCell(input_size=input_size, hidden_size=hidden_size)

    #(seq, batch, features)
    dataset = torch.rand(seq_len, batch_size, input_size)
    hidden = torch.zeros(batch_size, hidden_size)

    for idx, inputs in enumerate(dataset, 0):
        print("="*20, idx, "="*20)
        print("input size", inputs.shape)

        hidden = cell(inputs, hidden)

        print("output size", hidden.shape)
        print(hidden)


if __name__ == "__main__":
    main()
