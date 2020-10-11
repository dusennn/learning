import torch


class CNNet(torch.nn.Module):
    def __init__(self):
        super(CNNet, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, 10, kernel_size=5)
        self.conv2 = torch.nn.Conv2d(10, 20, kernel_size=5)
        self.pooling = torch.nn.MaxPool2d(2)
        self.fc1 = torch.nn.Linear(320, 160)
        self.fc2 = torch.nn.Linear(160, 80)
        self.fc3 = torch.nn.Linear(80, 10)
        self.relu = torch.nn.ReLU()
    
    def forward(self, x):
        batch_size = x.size(0)
        x = self.pooling(self.relu(self.conv1(x)))
        x = self.pooling(self.relu(self.conv2(x)))
        x = x.view(batch_size, -1)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)
        return x


class CNNet2(torch.nn.Module):
    '''
    Try a more complex CNN:
        - Conv2d Layer * 3
        - ReLU Layer * 3
        - MaxPooling Layer * 3
        - Linear Layer * 3
    '''
    def __init__(self):
        super(CNNet2, self).__init__()
        self.conv1 = torch.nn.Conv2d(1, 10, kernel_size=3)
        self.conv2 = torch.nn.Conv2d(10, 20, kernel_size=3)
        self.conv3 = torch.nn.Conv2d(20, 40, kernel_size=3)
        self.pooling1 = torch.nn.MaxPool2d(2)
        self.pooling2 = torch.nn.MaxPool2d(1)
        self.fc1 = torch.nn.Linear(360, 180)
        self.fc2 = torch.nn.Linear(180, 90)
        self.fc3 = torch.nn.Linear(90, 10)
        self.relu = torch.nn.ReLU()
    
    def forward(self, x):
        batch_size = x.size(0)
        x = self.pooling1(self.relu(self.conv1(x)))
        x = self.pooling1(self.relu(self.conv2(x)))
        x = self.pooling2(self.relu(self.conv3(x)))
        x = x.view(batch_size, -1)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)
        return x
