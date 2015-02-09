#include <ctime>

typedef unsigned long long uint64;
typedef long long int64;

namespace {
  //param == 1
  const double pMild = 0.000001;
  //param == 2
  const double pMedium = 0.0001;
  //param == 3
  const double pAggressive = 0.01;

  inline uint64 getRandomBitStream() {
    static uint64 x = time(0);
    x ^= (x >> 21);
    x ^= (x << 35);
    x ^= (x >> 4);
    return x;
  }

}

uint64 DummyinjectInst(char* opcode, int64 param, uint64 ret, uint64 op1,
    uint64 op2, char* type) {
  uint64 max_rand;
  int64* tmp = (int64*)(&max_rand);
  *tmp = -1;
  double rand_number = static_cast<double>(getRandomBitStream()) /
    static_cast<double>(max_rand);
  if ((param == 1 && rand_number < pMild)
      || (param == 2 && rand_number < pMedium)
      || (param == 3 && rand_number < pAggressive))
    return getRandomBitStream();

  return ret;
}
