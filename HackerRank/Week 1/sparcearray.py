n = int(input().strip())
strings = [input().strip() for _ in range(n)]
q = int(input().strip())
queries = [input().strip() for _ in range(q)]
for i in queries:
    count = strings.count(i)
    print(count)
