def solve():
    # Parse input
    parts = input().split()
    W = int(parts[0])
    H = int(parts[1])
    N = int(parts[2])

    photos = []
    for _ in range(N):
        x_ld, y_ld, x_ru, y_ru = map(int, input().split())
        photos.append((x_ld, y_ld, x_ru, y_ru))

    # If there's only one photo, Lisa can simply be there
    if N == 1:
        return "YES"

    # For each photo, calculate all possible positions
    all_positions = []
    for photo in photos:
        x_ld, y_ld, x_ru, y_ru = photo
        positions = set()
        for x in range(x_ld, x_ru + 1):
            for y in range(y_ld, y_ru + 1):
                positions.add((x, y))
        all_positions.append(positions)

    # If any photo has no possible positions, return "NO"
    if any(not positions for positions in all_positions):
        return "NO"

    # Use dynamic programming to track reachable positions
    # reachable[i] = set of positions for photo i that can be reached following a valid path

    # For the first photo, all positions are reachable (Lisa can start anywhere)
    reachable = [all_positions[0]]

    # Process each subsequent photo
    for i in range(1, N):
        current_reachable = set()

        # For each reachable position in previous photo
        for prev_pos in reachable[-1]:
            x1, y1 = prev_pos

            # For each position in current photo
            for curr_pos in all_positions[i]:
                x2, y2 = curr_pos

                # Check if positions are adjacent (Manhattan distance = 1)
                if abs(x1 - x2) + abs(y1 - y2) == 1:
                    current_reachable.add(curr_pos)

        # If no positions in this photo are reachable, return "NO"
        if not current_reachable:
            return "NO"

        reachable.append(current_reachable)

    return "YES"


print(solve())
