OPERATORS = {
    '+': (1, lambda x, y: x + y),
    '-': (1, lambda x, y: x - y),
    '~': (2, lambda x: -x),
    'u': (2, lambda x: x)
}


def eval_expression(s: str) -> int:
    s = s.replace(' ', '')

    def tokenize():
        i = 0
        n = len(s)
        while i < n:
            if s[i] in '+-()':
                if s[i] == '-' and (i == 0 or s[i - 1] in '+-~('):
                    yield '~'
                elif s[i] == '+' and (i == 0 or s[i - 1] in '+-~(u'):
                    yield 'u'
                else:
                    yield s[i]
                i += 1
            elif s[i].isdigit():
                j = i
                while j < n and s[j].isdigit():
                    j += 1
                yield int(s[i:j])
                i = j
            else:
                i += 1

    def shunting_yard(tokens):
        output = []
        stack = []

        for token in tokens:
            if isinstance(token, int):
                output.append(token)
            elif token == '(':
                stack.append(token)
            elif token == ')':
                while stack and stack[-1] != '(':
                    output.append(stack.pop())
                if stack:
                    stack.pop()
            else:
                if token in '~u':
                    while (stack and stack[-1] != '(' and
                           OPERATORS.get(stack[-1], (0,))[0] > OPERATORS[token][0]):
                        output.append(stack.pop())
                else:
                    while (stack and stack[-1] != '(' and
                           OPERATORS.get(stack[-1], (0,))[0] >= OPERATORS[token][0]):
                        output.append(stack.pop())
                stack.append(token)

        while stack:
            if stack[-1] == '(':
                stack.pop()
            else:
                output.append(stack.pop())

        return output

    def evaluate(rpn):
        stack = []
        for token in rpn:
            if isinstance(token, int):
                stack.append(token)
            elif token in ['~', 'u']:  # Handle unary operators
                if stack:
                    a = stack.pop()
                    stack.append(OPERATORS[token][1](a))
            else:  # Handle binary operators
                if len(stack) >= 2:
                    b = stack.pop()
                    a = stack.pop()
                    stack.append(OPERATORS[token][1](a, b))

        return stack[0] if stack else 0

    tokens = list(tokenize())
    rpn = shunting_yard(tokens)
    return evaluate(rpn)


print(eval_expression(str(input())))
