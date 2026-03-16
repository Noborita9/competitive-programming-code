#include <bits/stdc++.h>

using namespace std;

#define vec vector

using i32 = int;
using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;
using my_clock = chrono::steady_clock;

constexpr u32 DAYS = 365;
constexpr u32 CONTESTS = 26;
constexpr f64 SA_TIME = 1.950;

// struct Random {
// 	mt19937_64 engine;
// 	Random(): engine(my_clock::now().time_since_epoch().count()) {}
// 	template<class Int>Int integer(Int n) {return integer<Int>(0, n);} // `[0,n)`
// 	template<class Int>Int integer(Int l, Int r)
// 		{return uniform_int_distribution<Int>{l, r-1}(engine);} // `[l,r)`
// 	f64 real() {return uniform_real_distribution<f64>{}(engine);} // `[0,1)`
// } rng;

struct Random { // XorShift
    u32 x;
    Random(u32 seed): x(seed) {}
    inline u32 next() {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x >> 5;
        return x;
    }
    template<class Int>inline Int integer(Int l, Int r) { // [l, r]
        return next() % (r - l + 1) + l;
    }
    f64 real() {
        return (f64)next() / (f64)(1ull << 32);
    }

} rng(21312451);

struct Timer {
	using time = my_clock::time_point;
	time start = my_clock::now();
	double elapsed() { // Segundos desde el inicio.
		return chrono::duration<double>(my_clock::now() - start).count();
	}
};

struct Solution {
    vec<u32> days;
    Solution(vec<u32> s): days(s) {}
    void print() {
        for (u32 i = 0; i < days.size(); i ++) {
            cout << days[i] + 1 << "\n";
        }
    }
};

struct Input {
    u32 D;
    vec<i64> C;
    vec<vec<i64>> S;
} input;

void parse_input() {
    cin >> input.D;
    input.C.resize(CONTESTS);
    for (u32 i = 0; i < CONTESTS; i ++) {
        cin >> input.C[i];
    }
    input.S.resize(input.D);
    for (u32 i = 0; i < input.D; i ++) {
        input.S[i].reserve(CONTESTS);
        for (u32 j = 0; j < CONTESTS; j ++) {
            cin >> input.S[i][j];
        }
    }
}

struct Movement {
    u32 day;
    u32 contest;
};

struct State {
    vec<u32> C;
    vec<vec<u32>> occurences;

    State(): C(input.D), occurences(CONTESTS) {}
    State(vec<u32> C_): C(C_), occurences(CONTESTS) {
        for (u32 i = 0; i < CONTESTS; i ++) {
            occurences[i].push_back(0);
        }
        for (u32 i = 0; i < input.D; i ++) {
            occurences[C[i]].push_back(i + 1);
        }
        for (u32 i = 0; i < CONTESTS;i ++){
            occurences[i].push_back(input.D + 1);
        }
    }

    i64 get_e() {
        vec<u32> last(CONTESTS);
        i64 score = (i64)1e6;
        for (u32 d = 1; d <= input.D; d++) {
            score += input.S[d - 1][C[d - 1]];
            last[C[d-1]] = d;
            for (u32 j = 0; j < CONTESTS;j ++) {
                score -= input.C[j] * (d - last[j]);
            }
        }
        return score;
    }


};

i64 gap[380];

struct StateSearch {
    Movement to_apply;
    Movement to_rollback;
    State *state;
    StateSearch(State * s): state(s) {}

    void generate() {
        // Pick next movement and rollback strategy
        u32 ix = rng.integer<u32>(0, input.D - 1);
        u32 c_ix = rng.integer<u32>(0, CONTESTS - 1);
        set(to_apply, ix, c_ix);
        set(to_rollback, ix, state->C[ix]);
    }

    void set(Movement &m, const u32 day, const u32 contest) {
        m.day = day;
        m.contest = contest;
    }

    i64 calculate_delta() {
        u32 d = to_apply.day + 1;
        u32 old_c = to_rollback.contest;
        u32 new_c = to_apply.contest;
        if (old_c == new_c) return 0;

        i64 delta = 0;
        delta += input.S[d - 1][new_c] - input.S[d - 1][old_c]; // Satisfaction from the day

        {
            auto &v = state->occurences[old_c];
            auto it = lower_bound(v.begin(), v.end(), d);
            i64 prv = *prev(it);
            i64 nxt = *next(it);
            delta += input.C[old_c] * gap[d - prv];
            delta += input.C[old_c] * gap[nxt - d];
            delta -= input.C[old_c] * gap[nxt - prv];
        }
        {
            auto &v = state->occurences[new_c];
            auto it = lower_bound(v.begin(), v.end(), d);
            i64 prv = *prev(it);
            i64 nxt = *it;
            delta -= input.C[new_c] * gap[d - prv];
            delta -= input.C[new_c] * gap[nxt - d];
            delta += input.C[new_c] * gap[nxt - prv];
        }
        return delta;
    }

    void apply() {
        {
            auto &v = state->occurences[to_rollback.contest];
            auto it = lower_bound(v.begin(), v.end(), to_rollback.day + 1);
            v.erase(it);
        }
        {
            auto &v = state->occurences[to_apply.contest];
            auto it = lower_bound(v.begin(), v.end(), to_rollback.day + 1);
            v.insert(it, to_apply.day + 1);
        }
        state->C[to_apply.day] = to_apply.contest;
    }
};

State greedy_state() {
    vec<u32> ans(input.D, 0);
    vec<u32> last(CONTESTS, 0);
    for (u32 d = 1; d <= input.D; d++) {
        u32 ix = CONTESTS;
        i64 best_score = 0;
        for (u32 j = 0; j < CONTESTS;j ++) {
            i64 not_use_j = input.C[j] * (d - last[j]);
            if (ix == CONTESTS || (not_use_j + input.S[d-1][j]) > best_score) {
                ix = j;
                best_score = (not_use_j + input.S[d - 1][j]);
            }
        }
        last[ix] = d;
        ans[d - 1] = ix;
    }
    return State(std::move(ans));
}

Solution solve() {
    // Counters
    //
    u64 iterations = 0;

    State current = greedy_state();
    State best = current;
    StateSearch sa(&current);

    f64 temp_start = (f64)5000.0;
    f64 temp_end = (f64)10.0;
    i64 best_e = best.get_e();
    i64 cur_e = best_e;

    Timer start_time;

    while (start_time.elapsed() < SA_TIME) {
        iterations++;
        f64 progress = start_time.elapsed() / SA_TIME;
        f64 temp = temp_start * (1 - progress) + temp_end * progress;
        sa.generate();
        i64 delta = sa.calculate_delta();
        if (delta > 0 || exp((f64)delta / temp) > rng.real()) {
            sa.apply();
            cur_e += delta;
            if (cur_e > best_e) {
                best_e = cur_e;
                best.C = current.C;
            }
        } 
    }

    cerr << "Total Iterations: " << iterations << "\n";
    return Solution(std::move(best.C)); // We should build the solution here!
}

int main() { // Clear main
    ios::sync_with_stdio(0);
    cin.tie(0);

    parse_input();

    Solution sol = solve();

    sol.print();
}
