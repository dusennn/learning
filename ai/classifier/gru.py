import torch

from torch.nn.utils.rnn import (pack_padded_sequence, )
from root import (create_tensor, )


class Net(torch.nn.Module):
    def __init__(self, input_size, hidden_size, output_size, num_layer=1, bidirectional=True, use_gpu=False):
        super(Net, self).__init__()
        self.hidden_size = hidden_size
        self.num_layer = num_layer
        self.num_directions = 2 if bidirectional else 1
        self.use_gpu = use_gpu

        self.embedding = torch.nn.Embedding(input_size, hidden_size)
        self.gru = torch.nn.GRU(hidden_size, hidden_size, num_layer, bidirectional=bidirectional)
        self.fc = torch.nn.Linear(hidden_size * self.num_directions, output_size)

    def _init_hidden(self, batch_size):
        hidden = torch.zeros(self.num_layer * self.num_directions, batch_size, self.hidden_size)
        return create_tensor(hidden, self.use_gpu)        

    def forward(self, inputs, seq_lengths):
        inputs = inputs.t()
        batch_size = inputs.size(1)

        hidden = self._init_hidden(batch_size)
        embedding = self.embedding(inputs)

        gru_input = pack_padded_sequence(embedding, seq_lengths)
        
        output, hidden = self.gru(gru_input, hidden)
        if self.num_directions == 2:
            hidden_cat = torch.cat([hidden[-1], hidden[-2]], dim=1)
        else:
            hidden_cat = hidden[-1]
        fc_output = self.fc(hidden_cat)        
        return fc_output

