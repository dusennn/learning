import torch


class InspectionA(torch.nn.Module):
    def __init__(self, in_channels):
        super(InspectionA, self).__init__()
        self.avg_pooling = torch.nn.AvgPool2d(1)

        self.conv_1x1_1 = torch.nn.Conv2d(in_channels, 16, kernel_size=1, stride=1, padding=1)
        self.conv_1x1_2 = torch.nn.Conv2d(in_channels, 24, kernel_size=1, stride=1, padding=1)

        self.conv_3x3_1 = torch.nn.Conv2d(16, 24, kernel_size=3, stride=1, padding=1)
        self.conv_3x3_2 = torch.nn.Conv2d(24, 24, kernel_size=3, stride=1, padding=1)

        self.conv_5x5 = torch.nn.Conv2d(16, 24, kernel_size=5, padding=2)

        self.relu = torch.nn.ReLU()

    def forward(self, x):
        branch1 = self.conv_1x1_2(self.avg_pooling(x))
        branch2 = self.conv_1x1_1(x)
        branch3 = self.conv_5x5(self.conv_1x1_1(x))
        branch4 = self.conv_3x3_2(self.conv_3x3_1(self.conv_1x1_1(x)))
        return torch.cat([branch1, branch2, branch3, branch4], dim=1)

        
class GoogLeNet(torch.nn.Module):
    def __init__(self):
        super(GoogLeNet, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, 10, kernel_size=5)
        self.conv2 = torch.nn.Conv2d(88, 20, kernel_size=5)

        self.incep1 = InspectionA(in_channels=10)
        self.incep2 = InspectionA(in_channels=20)

        self.mp = torch.nn.MaxPool2d(2)
        self.fc1 = torch.nn.Linear(4312, 1024)
        self.fc2 = torch.nn.Linear(1024, 256)
        self.fc3 = torch.nn.Linear(256, 64)
        self.fc4 = torch.nn.Linear(64, 10)
        self.relu = torch.nn.ReLU()

    def forward(self, x):
        in_size = x.size(0)
        x = self.relu(self.mp(self.conv1(x)))
        x = self.incep1(x)
        x = self.relu(self.mp(self.conv2(x)))
        x = self.incep2(x)
        x = x.view(in_size, -1)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)
        x = self.fc4(x)
        return x
    