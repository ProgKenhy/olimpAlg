def solve():
    W, H = map(int, input().split())
    N = int(input())

    photos = []
    for _ in range(N):
        x_ld, y_ld, x_ru, y_ru = map(int, input().split())
        photos.append((x_ld, y_ld, x_ru, y_ru))

    if N == 1:
        return "Yes"

    all_positions = []
    for photo in photos:
        x_ld, y_ld, x_ru, y_ru = photo
        positions = set()
        for x in range(x_ld, x_ru + 1):
            for y in range(y_ld, y_ru + 1):
                positions.add((x, y))
        all_positions.append(positions)

    if any(not positions for positions in all_positions):
        return "No"

    current_reachable = all_positions[0].copy()

    for i in range(1, N):
        next_reachable = set()
        for prev_pos in current_reachable:
            x1, y1 = prev_pos
            for curr_pos in all_positions[i]:
                x2, y2 = curr_pos
                if abs(x1 - x2) + abs(y1 - y2) == 1:
                    next_reachable.add(curr_pos)
        if not next_reachable:
            return "No"
        current_reachable = next_reachable
    return "Yes"


print(solve())
