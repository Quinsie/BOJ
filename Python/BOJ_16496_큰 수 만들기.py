import sys
import functools

class problem:
    def __init__(self, n = 0, list = []):
        self.num = n
        self.num_list = list
    
    def list_sort(self):
        self.num_list.sort(key = functools.cmp_to_key(compare))

    def return_first(self):
        return self.num_list[0]
    
    def print_all(self):
        for i in self.num_list:
            print(i, end = '')

def compare(a, b):
    ab = a + b
    ba = b + a
    
    if a == b: return 1
    if ab > ba: return -1
    else: return 1
    
def solve():
    pb = problem(int(sys.stdin.readline()), list(sys.stdin.readline().rstrip().split()))
    pb.list_sort()

    if pb.return_first() == '0':
        print(0)
    else:
        pb.print_all()

if __name__ == "__main__":
    solve()