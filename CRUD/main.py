import random

class RandomSet:
    def __init__(self):
        self.dict = {}
        self.list = []

    def add(self, x) -> bool:
        if x in self.dict:
            return False
        self.dict[x] = len(self.list)
        self.list.append(x)
        return True

    def contains(self, x) -> bool:
        return x in self.dict

    def remove(self, x) -> bool:
        if x not in self.dict:
            return False
        last_elem = self.list[-1]
        index_to_remove = self.dict[x]

        self.list[index_to_remove] = last_elem
        self.dict[last_elem] = index_to_remove

        self.list.pop()
        del self.dict[x]
        return True

    def getRandom(self):
        return random.choice(self.list)

my_set = RandomSet()
my_set.add(1)
my_set.add(2)
my_set.add(3)
print(my_set.getRandom())
print(my_set.getRandom())
print(my_set.getRandom())
my_set.add(4)
my_set.remove(2)
print(my_set.dict)
print(my_set.list)