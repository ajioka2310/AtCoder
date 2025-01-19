# Class 化
DEBUG = 0

class BitDpInfo():
    def __init__(self, base, I, calc_nstate, contribution, leading_zero_consideration, init_state, result_condition):
        self.base = base
        self.I = I
        self.init_state = init_state
        self.result_condition = result_condition
        self.count = [[0] * I for _ in range(2)]
        self.count_next = [[0] * I for _ in range(2)]
        
        self.contribution = contribution
        if contribution is not None:
            self.value = [[0] * I for _ in range(2)]
            self.value_next = [[0] * I for _ in range(2)]
        
        self.calc_nstate = calc_nstate
        if leading_zero_consideration:
            self.moves = [[None] * self.base for _ in range(2)]
            self.leading_zero_consideration = 1
            self.is_starting = 1
        else:
            self.moves = [[None] * self.base for _ in range(1)]
            self.leading_zero_consideration = 0
            self.param = self.count[0][0] = 1
            self.is_starting = 0
    
    def bit_dp_from_top(self, target_digit, is_starting):
        L = []
        for flg, nflg, l, r in self.bit_dp_from_top_lr(target_digit, is_starting):
            for digit in range(l, r):
                L.append((flg, nflg, digit))
        return L
    def bit_dp_from_top_lr(self, target_digit, is_starting):
        # (from, to, l, r) を返す
        # from と to は、今見ている桁から上の部分が N と一致しているかどうかを返す
        #     0: 一致している
        #     1: N より真に小さい
        # 行き先の digit の範囲が [l, r)

        yield (0, 0, max(is_starting, target_digit), target_digit + 1)
        yield (0, 1, is_starting, target_digit)
        yield (1, 1, 0, self.base)
        if self.leading_zero_consideration:
            if is_starting:
                if target_digit > 1:
                    yield (-1, 1, 1, target_digit)
                yield (-1, 0, max(1, target_digit), target_digit + 1)
            else:
                yield (-1, 1, 1, self.base)

    def transition(self, k, target_digit, po):
        if 1:
            for exceed, nexceed, l, r in self.bit_dp_from_top_lr(target_digit, self.is_starting):
                for digit in range(l, r):
                    self.transition_each(exceed, nexceed, k, digit, po)
        else:
            if self.moves[self.is_starting][target_digit] is None:
                self.moves[self.is_starting][target_digit] = self.bit_dp_from_top(target_digit, self.is_starting)
            for exceed, nexceed, digit in self.moves[self.is_starting][target_digit]:
                self.transition_each(exceed, nexceed, k, digit, po)
            
        self.count = self.count_next
        self.count_next = [[0] * I for _ in range(2)]
        if self.contribution is not None:
            self.value = self.value_next
            self.value_next = [[0] * I for _ in range(2)]
        if self.leading_zero_consideration and target_digit:
            self.is_starting = 0
    
    def transition_each(self, ex, nex, k, digit, po):
        c2 = self.count_next[nex]
        if self.contribution is not None:
            v2 = self.value_next[nex]
        
        init_value = 0
        
        if ex < 0:
            # Leading Zero 考慮する場合のみ
            
            ##### 遷移ここから #####
            state = self.init_state
            c = 1
            v = init_value
            nstate = self.calc_nstate(state, digit, k, po) # <- 遷移先
            c2[nstate] = (c2[nstate] + 1) % P if P else c2[nstate] + 1
            if self.contribution is not None:
                if P:
                    v2[nstate] = (v2[nstate] + v + c * self.contribution(state, digit, k, po)) % P
                else:
                    v2[nstate] += v + c * self.contribution(state, digit, k, po)
            ##### ここまで #####
        else:
            c1 = self.count[ex]
            if self.contribution is not None:
                v1 = self.value[ex]
            ##### 遷移ここから #####
            for state, c in enumerate(c1):
                if not c:
                    continue
                nstate = self.calc_nstate(state, digit, k, po) # <- 遷移先
                if P:
                    c2[nstate] = (c2[nstate] + c) % P
                else:
                    c2[nstate] += c
                if self.contribution is not None:
                    v = v1[state]
                    v2[nstate] = (v2[nstate] + v + c * self.contribution(state, digit, k, po)) % P
            ##### ここまで #####
    
    def calc(self, N):
        if type(N) == int:
            NN = [int(a) for a in str(N)][::-1]
        elif type(N) == str:
            NN = [int(a) for a in N][::-1]
        else:
            NN = N
        if P:
            po = pow(self.base, len(NN) - 1, P)
            base_inv = pow(self.base, P - 2, P)
        else:
            po = 1
        for k in range(len(NN))[::-1]:
            target_digit = NN[k]
            self.transition(k, target_digit, po)
            if P:
                po = po * base_inv % P
    
    def result(self):
        if self.contribution is None:
            x = self.count
        else:
            x = self.value
        ans = 0
        for i in range(I):
            if self.result_condition(i):
                ans += x[0][i] + x[1][i]
        return ans % P if P else ans
    
    def __str__(self):
        print("sum =", sum(self.value[0]) + sum(self.value[1]))
        return str([self.count, self.value])

if 0:
    # https://atcoder.jp/contests/abc235/tasks/abc235_f
    P = 998244353
    NN = input()
    M = int(input())
    C = [int(a) for a in input().split()]
    I = 1 << M
    mmm = I - 1
    A = [0] * 10
    for i, c in enumerate(C):
        A[c] = 1 << i

    def calc_next_state(state, digit, k, po):
        return state | A[digit]
    def contribution(state, digit, k, po):
        return digit * po % P
    def result_condition(s):
        return s == mmm
    leading_zero_consideration = 1
    base = 10
    init_state = 0
    bit_dp_info = BitDpInfo(base, I, calc_next_state, contribution, leading_zero_consideration, init_state, result_condition)
    bit_dp_info.calc(NN)
    print(bit_dp_info.result())
elif 0:
    # https://atcoder.jp/contests/abc208/tasks/abc208_e
    N, K = map(int, input().split())
    S = [0]
    D = {0: 0}
    M = 19
    cnt = 1
    for i2 in range(M * 3 + 1):
        c2 = (i2 + 2) // 3
        for i3 in range(M * 2 + 1):
            c3 = (i3 + 1) // 2
            if c2 + c3 > M:
                continue
            for i5 in range(M + 1):
                c5 = i5
                if c2 + c3 + c5 > M:
                    continue
                for i7 in range(M + 1):
                    c7 = i7
                    if c2 + c3 + c5 + c7 > M:
                        continue
                    a = 2 ** i2 * 3 ** i3 * 5 ** i5 * 7 ** i7
                    D[a] = cnt
                    S.append(a)
                    cnt += 1
    if 0:
        print(cnt)
        print("S =", S)
    I = len(S)
    calc_next_state = lambda s, digit, k, po: D[S[s] * digit]
    contribution = None
    result_condition = lambda s: S[s] <= K
    P = 0
    leading_zero_consideration = 1
    base = 10
    init_state = 1
    bit_dp_info = BitDpInfo(base, I, calc_next_state, contribution, leading_zero_consideration, init_state, result_condition)
    bit_dp_info.calc(N)
    print(bit_dp_info.result())
elif 1:
    # https://atcoder.jp/contests/tdpc/tasks/tdpc_number
    P = 10 ** 9 + 7
    D = int(input())
    N = int(input())
    I = D

    def calc_next_state(state, digit, k, po):
        return (state + digit) % I
    # def contribution(state, digit, k, po):
    #     return 1
    contribution = None
    def result_condition(s):
        return s == 0
    leading_zero_consideration = 1
    base = 10
    init_state = 0
    bit_dp_info = BitDpInfo(base, I, calc_next_state, contribution, leading_zero_consideration, init_state, result_condition)
    bit_dp_info.calc(N)
    print(bit_dp_info.result())