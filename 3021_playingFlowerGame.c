int countOdd(int L, int R){

    int N = (R - L) / 2;

    // if either R or L is odd
    if (R % 2 != 0 || L % 2 != 0)
        N += 1;

    return N;
}

long long flowerGame(int n, int m) {
  long long oddsN = countOdd(1, n);
  long long oddsM = countOdd(1, m);
  long long evensN = (n - 1 + 1) - oddsN;
  long long evensM = (m - 1 + 1) - oddsM;

  return oddsN * evensM + evensN * oddsM;
}
