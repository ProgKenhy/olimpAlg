import random

def generate_test_case(W, H, N):
    print(W, H)
    print(N)
    for _ in range(N):
        x1 = random.randint(1, W)
        y1 = random.randint(1, H)
        x2 = random.randint(x1, W)
        y2 = random.randint(y1, H)
        print(x1, y1, x2, y2)

# Пример использования:
W = 300
H = 300
N = 1000  # Количество снимков
generate_test_case(W, H, N)
