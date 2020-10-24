import time, torch, math
import matplotlib.pyplot as plt


def time_since(since):
    s = time.time() - since
    m = math.floor(s / 60)
    s -= m * 60
    return '%dm %ds' % (m, s)


def evaluation(acc_list):
    x = list(range(acc_list))
    y = acc_list
    plt.plot(x, y)
    plt.xlabel('Epoch')
    plt.ylabel('Accuracy')
    plt.grid()
    plt.show()


def name2list(name):
    arr = [ord(c) for c in name]
    return arr, len(arr)


def create_tensor(tensor, use_gpu=False):
    if use_gpu:
        device = torch.device("cude:0")
        tensor =tensor.to(device)
    return tensor


def make_tensors(names, countries, use_gpu=False):
    sequences_and_lengths = [name2list(name) for name in names]
    name_sequences = [sl[0] for sl in sequences_and_lengths]
    seq_lengths = torch.LongTensor([sl[1] for sl in sequences_and_lengths])
    countries = countries.long()

    seq_tensor = torch.zeros(len(name_sequences), seq_lengths.max()).long()
    for idx, (seq, seq_len) in enumerate(zip(name_sequences, seq_lengths), 0):
        seq_tensor[idx, :seq_len] = torch.LongTensor(seq)

    seq_lengths, perm_idx = seq_lengths.sort(dim=0, descending=True)
    seq_tensor = seq_tensor[perm_idx]
    countries = countries[perm_idx]
    
    return (
        create_tensor(seq_tensor, use_gpu), create_tensor(seq_lengths, use_gpu), 
        create_tensor(countries, use_gpu)
    )
