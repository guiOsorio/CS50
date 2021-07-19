def simple():
    scores = [72, 73, 33]
    average = sum(scores) / len(scores)

    print(f"Average: {average}")

def advanced():
    scores = []
    for i in range(3):
        num = int(input("Add to scores: "))
        scores.append(num)
    average = sum(scores) / len(scores)
    print(f"Average: {average}")


simple()
advanced()