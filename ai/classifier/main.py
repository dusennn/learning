import time
import torch

from root import (time_since, evaluation, )


def main():
    classifier = RNNClassifier(n_chars, hidden_size, n_country, n_layer)
    if use_gpu:
        device = torch.device("cude:0")
        classifier.to(device)
    
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(classifier.parameters(), lr=0.01)

    start = time.time()
    print("Training for %d epochs..." % n_epochs)
    acc_list = []
    for epoch in range(1, n_epochs+1):
        train_model()
        acc = test_model()
        acc_list.append(acc)


if __name__ == "__main__":
    main()
