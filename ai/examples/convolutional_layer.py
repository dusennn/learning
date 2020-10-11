import torch


def main():
    in_channels, out_channels = 5, 10
    width, height = 100, 100
    kernel_size = 3
    batch_size = 1

    inputs = torch.randn(batch_size, in_channels, width, height)
    conv_layer = torch.nn.Conv2d(in_channels, out_channels, kernel_size=kernel_size)

    outputs = conv_layer(inputs)

    print(inputs.shape)
    print(outputs.shape)
    print(conv_layer.weight.shape)

if __name__ == "__main__":
    main()
