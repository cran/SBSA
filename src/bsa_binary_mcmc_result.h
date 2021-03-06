#ifndef BSA_BINARY_MCMC_RESULT_H
#define BSA_BINARY_MCMC_RESULT_H

#include "bsalite.h"
#include <RcppArmadillo.h>

using namespace arma;

class BSABinaryMCMCResult {
public:
   BSABinaryMCMCResult(const int n, const int p)
    : acc(5),
      alphas(2, n),
      beta_zs(p, n),
      gamma_zs(p, n),
      tau_sqs(p, n),
      gamma_xs(n),
      beta_us(n),
      i()
  {}

  void change(const int block);

  void add(ThetaBinary model);

  Rcpp::List result() const;

private:
  // count how many times a block sampling resulted in parameter update
  std::vector<int> acc;

  // parameter value at the end of each iteration through all blocks
  mat alphas;
  mat beta_zs;
  mat gamma_zs;
  mat tau_sqs;
  std::vector<double> gamma_xs;
  std::vector<double> beta_us;

  int i;
};

#endif
