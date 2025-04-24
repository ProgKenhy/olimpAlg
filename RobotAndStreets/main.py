from collections import defaultdict

def main():
    n = int(input())
    from_counts = defaultdict(int)
    to_counts = defaultdict(int)

    for _ in range(n):
        parts = input().split()
        a1, h1, a2, h2 = parts[0], int(parts[1]), parts[2], int(parts[3])
        from_addr = (a1, h1)
        to_addr = (a2, h2)
        from_counts[from_addr] += 1
        to_counts[to_addr] += 1

    start_candidates = []
    end_candidates = []
    all_addrs = set(from_counts.keys()).union(set(to_counts.keys()))

    for addr in all_addrs:
        diff = from_counts.get(addr, 0) - to_counts.get(addr, 0)
        if diff == 1:
            start_candidates.append(addr)
        elif diff == -1:
            end_candidates.append(addr)

    if len(start_candidates) == 1 and len(end_candidates) == 1:
        start = start_candidates[0]
        end = end_candidates[0]
        print(f"{start[0]} {start[1]} {end[0]} {end[1]}")
    else:
        print(-1)

if __name__ == "__main__":
    main()
