



class Stack:
    def __init__(self, max_size):
        self.max_size = max_size
        self.stack = [0] * max_size
        self.top = -1

    def is_empty(self):
        if self.top == -1:
            return True
        else:
            return False

    def push(self, data):
        if self.top >= self.max_size - 1:
            print('堆疊已滿')
        else:
            self.top += 1
            self.stack[self.top] = data

    def pop(self):
        if self.is_empty():
            print('堆疊已空')
        else:
            print('彈出 %d' % self.stack[self.top])
            self.top -= 1

    def print_stack(self):
        for i in range(self.top, -1, -1):
            print('--%d--' % self.stack[i])
        print('-----')

if __name__ == '__main__':
    max_size = 5
    s = Stack(max_size)
    s.push(1)
    s.push(2)
    s.push(3)
    s.pop()
    s.print_stack()
