def eratos(N):
    srN = int(N ** 0.5)
    nums = [PRIME for _ in range(N + 1)]

    nums[0] = nums[1] = NO_PRIME

    for i in range(2, srN + 1):
        if nums[i] == NO_PRIME:
            continue
        for j in range(i * 2, N + 1, i):
            nums[j] = NO_PRIME
    primes = []
    for i in range(N + 1):
        if nums[i] == PRIME:
            primes.append(i)

    return primes

N = int(input())

PRIME = 1
NO_PRIME = 2

primes = eratos(N)
nCPS = 0
left = right = 0
psum = 0

while True:
    if psum >= N:
        psum -= primes[left]
        left += 1
    else:
        if right == len(primes):
            break
        psum += primes[right]
        right += 1
    if psum == N:
        nCPS += 1

print(nCPS)