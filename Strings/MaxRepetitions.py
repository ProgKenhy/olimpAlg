from collections import defaultdict


def max_consec_chars(s: str) -> dict:
    if not s:
        return {}

    max_counts = defaultdict(int)
    cur_char = s[0].lower()
    count = 1


    for char in s[1:]:
        char = char.lower()
        if not char.isalpha(): continue

        if cur_char == char:
            count += 1

        else:
            max_counts[cur_char] = max(max_counts[cur_char], count)
            count = 1
            cur_char = char

    max_counts[cur_char] = max(max_counts[cur_char], count)


    return dict(max_counts)

if __name__ == '__main__':
    s = "aaa bbb a b abababab"
    print(max_consec_chars(s))