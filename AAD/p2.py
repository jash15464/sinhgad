import heapq

class Node:
    def __init__(self, data, freq, left=None, right=None):
        self.data=data
        self.freq=freq
        self.left=left
        self.right=right
    
    def __lt__(self, other):
        return self.freq<other.freq

    def __del__(self):
        del self.left
        del self.right

def print_code(root, str):
    if not root:
        return 
    
    if not root.left and not root.right:
        print(f"{root.data} {str} Required Bits: {root.freq * len(str)}")
        return 

    print_code(root.left, str+'0')
    print_code(root.right, str+'1')

def haffman_coding(char_freq):
    queue=[Node(data, freq) for data, freq in char_freq]
    heapq.heapify(queue)

    while len(queue)>1:
        left=heapq.heappop(queue)
        right=heapq.heappop(queue)

        merged=Node('$', left.freq + right.freq, left, right)
        heapq.heappush(queue, merged)

    print("\nCharacter Code: ")
    print_code(queue[0],"")


if __name__== "__main__":

    num= int(input("Enter the number of characters: "))
    char_freq=[]
    for i in range (num):
        c=input("Enter the character: ")
        freq=int(input("Enter the frequency of character: "))
        char_freq.append((c, freq))
    
    haffman_coding(char_freq)
