def fractional_knapsack(weight, items):
    items.sort(key=lambda item: item[1], reverse=True)
    result = 0.0

    for item in items:
        if item[0] <= weight:
            result += item[0] * item[1]
            weight -= item[0]
        else:
            result += weight * item[1]
            break  

    return result

if __name__ == "__main__":
    num = int(input("Enter the number of items: "))
    weight = float(input("Enter the available weight in knapsack: "))
    items = []

    for i in range(num):
        itemValue = float(input("Enter the value of item: "))
        itemWeight = float(input("Enter the weight of item: "))

        # Store (weight, value per kg) in the items list
        items.append((itemWeight, itemValue / itemWeight))

    print(f"Max value in the knapsack: {fractional_knapsack(weight, items)}")
