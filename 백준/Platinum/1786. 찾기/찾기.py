def rabin_karp(): # 라빈 카프 알고리즘
    base = 31
    mod = 10 ** 9 + 7
    word_hash = 0
    pattern_hash = 0
    base_pow = 1
    cnt = 0
    word_list = []

    if len(word) < len(pattern):
        return 0, []

    for _ in range(len(pattern) - 1):
        base_pow = (base_pow * base) % mod

    for i in range(len(pattern)):
        pattern_hash = (pattern_hash * base + ord(pattern[i])) % mod # pattern의 초기 해시값
        word_hash = (word_hash * base + ord(word[i])) % mod  # 단어의 초기 해시값

    for i in range(len(word) - (len(pattern) - 1)):
        if i > 0: # i가 0일때는 이미 초기값이 들어있음 초기에 한번 돌고 그 다음부터 해시값 갱신
            word_hash = (word_hash - ord(word[i - 1]) * base_pow) % mod
            word_hash = (word_hash * base + ord(word[i + len(pattern) - 1])) % mod
            word_hash = (word_hash + mod) % mod
        # 해시값을 설정할때 밑이 소수이기 때문에 해시 충돌이 일어날 확률이 적음 (해시값이 같다면 같은 문자열로 판단).
        if word_hash == pattern_hash:
            cnt += 1
            word_list.append(i + 1)

    return cnt, word_list                

word = str(input())
pattern = str(input())
cnt = 0
word_list = []
cnt, word_list = rabin_karp()

print(cnt)
print(*word_list)