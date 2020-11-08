import gzip, csv

from torch.utils.data import (Dataset, )


class NameDataset(Dataset):
    def __init__(self, is_train_set=True):
        filename = 'dataset/names_{}.csv.gz'.format('train' if is_train_set else 'test')
        with gzip.open(filename, 'rt') as f:
            reader = csv.reader(f)
            rows = list(reader)
        self.names = [row[0] for row in rows]
        self.len = len(self.names)
        self.countries = [row[1] for row in rows]
        self.country_list = list(sorted(set(self.countries)))
        self.country_dict = self.get_country_dict()
        self.country_num = len(self.country_list)

    def __getitem__(self, index):
        return self.names[index], self.country_dict[self.countries[index]]

    def __len__(self):
        return self.len

    def get_country_dict(self):
        country_dict = dict()
        for idx, country_name in enumerate(self.country_list, 0):
            country_dict[country_name] = idx
        return country_dict        

    def idx2country(self, index):
        return self.country_list[index]

    def get_country_num(self):
        return self.country_num
