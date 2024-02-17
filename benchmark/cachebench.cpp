
#include <benchmark/benchmark.h>
#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <random>
#include <cstdint>

using namespace std;


static std::vector<int> RNG(int const low, int const high, int count) {
    std::vector<int> v;
    v.reserve(count);
    /*
    for (int i = 0; i < count; i++)
        v.push_back((std::rand() % high) + low);
        */

    static std::random_device r;
    static std::default_random_engine e(r());
    std::uniform_int_distribution<int> rng(low, high);

    for (int i = 0; i < count; i++)
        v.push_back(rng(e));

    return v;
}

static void cachebench(benchmark::State& s) {
    int bytes = 1 << s.range(0);
    int count = (bytes/sizeof(int)/2);
    vector<int32_t> indices; 
    vector<int32_t> numbers; 
    indices.reserve(count);
    numbers.reserve(count);
    for (auto i : RNG(std::numeric_limits<int>::min(), 
            std::numeric_limits<int>::max(), count))
        numbers.push_back(i);

    for (auto i : RNG(0, count, count))
        indices.push_back(i);

    for (auto _ : s) {
        long sum = 0;
        for (auto const& idx : indices) {
            sum += numbers[idx];
            benchmark::DoNotOptimize(sum);
        }
    }

    s.SetBytesProcessed(long(s.iterations()) * bytes);
    s.SetLabel(to_string(bytes/1024)+ "K");
}

BENCHMARK(cachebench)->DenseRange(13,26)->ReportAggregatesOnly(true);


BENCHMARK_MAIN();

