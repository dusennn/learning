import torch


def main():
    inputs = [
        3, 4, 6, 5, 
        2, 4, 6, 8,
        1, 6, 7, 8, 
        9, 7, 4, 6,
    ]
    inputs = torch.Tensor(inputs).view(1, 1, 4, 4)

    max_pooling_layer = torch.nn.MaxPool2d(kernel_size=2)

    outputs = max_pooling_layer(inputs)
    print(outputs)

if __name__ == "__main__":
    main()
