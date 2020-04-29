#include <iostream>

#include <assert.h>

#include <endstream/endofstream.h>
#include <endstream/endifstream.h>

using namespace rayzz::endstream;

static void run_trial(endianness ness) {
    const char* filename = "foo.out";
    endofstream fout(std::ofstream(filename, std::ios::binary), ness);
    uint16_t foo = 2;
    int32_t bar = 3;
    fout << foo << bar;
    fout.close();

    endifstream fin(std::ifstream(filename, std::ios::binary), ness);
    uint16_t foo_again;
    int32_t bar_again;
    fin >> foo_again >> bar_again;
    fin.close();

    assert(foo == foo_again);
    assert(bar == bar_again);
    remove(filename);
}

int main() {
    run_trial(endianness::ES_BIG_ENDIAN);
    run_trial(endianness::ES_LITTLE_ENDIAN);
    std::cout << "All the asserts passed!" << std::endl;
    return 0;
}