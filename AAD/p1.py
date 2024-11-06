def fibRecu(num, result):
    if num <= 1:
        result[num] = num
        return result[num]

    result[num] = fibRecu(num - 1, result) + fibRecu(num - 2, result)
    return result[num]

def fibRecuMemo(num, result):
    if num <= 1:
        result[num] = num
        return result[num]
    if result[num]!=-1:
        return result[num]

    result[num] = fibRecuMemo(num - 1, result) + fibRecuMemo(num - 2, result)
    return result[num]

if __name__ == "__main__":
    num = int(input("Enter the number: "))
    print("\nRecursion O(2^n)")
    result = [-1] * (num + 1)
    fibRecu(num, result)

    for i in result:
        print(i, end="  ")


    print("\n\nRecursion + Memoization O(n^2)")
    result=[-1]*(num+1)
    fibRecuMemo(num, result)

    for i in result:
        print(i, end="  ")

    print("\n\nTabulation O(n)")

    first=0
    second=1

    print(f"{first}  {second}",end="  ")
    for i in range (num-1):
        third=first+second
        print(third, end="  ")
        first=second
        second=third




