import torch


class ResidualBlock(torch.nn.Module):
    def __init__(self, channels):
        super(ResidualBlock, self).__init__()
        self.conv1 = torch.nn.Conv2d(channels, channels, kernel_size=3, padding=1)
        self.conv2 = torch.nn.Conv2d(channels, channels, kernel_size=3, padding=1)

        self.relu = torch.nn.ReLU()

    def forward(self, x):
        x = self.relu(self.conv1(x))
        x = self.relu(x + self.conv2(x))
        return x


class RSNet(torch.nn.Module):
    def __init__(self):
        super(RSNet, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, 16, kernel_size=5)
        self.conv2 = torch.nn.Conv2d(16, 32, kernel_size=5)

        self.rsblock1 = ResidualBlock(16)
        self.rsblock2 = ResidualBlock(32)

        self.pooling = torch.nn.MaxPool2d(2)
        self.relu = torch.nn.ReLU()
        self.fc1 = torch.nn.Linear(512, 256)
        self.fc2 = torch.nn.Linear(256, 64)
        self.fc3 = torch.nn.Linear(64, 10)
    
    def forward(self, x):
        batch_size = x.size(0)
        x = self.pooling(self.relu(self.conv1(x)))
        x = self.rsblock1(x)
        x = self.pooling(self.relu(self.conv2(x)))
        x = self.rsblock2(x)
        x = x.view(batch_size, -1)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)
        return x
