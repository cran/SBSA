#ifndef BSA_BINARY_WALKER_H
#define BSA_BINARY_WALKER_H

#include "bsalite.h"
#include "log_binary_functor.h"

class McmcReparametrizingBinarySampler {
public:
  McmcReparametrizingBinarySampler(const LogBinaryLik& loglik_, 
                                   const LogBinaryPri& logpri_, 
                                   const double sample_jump_)
    : loglik(loglik_), 
      logpri(logpri_),
      sample_jump(sample_jump_)
  {}
  
  bool sample(ThetaBinary& theta, double& log_lik, double& log_pri) const;
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const = 0;
  const double sample_jump;
private:
  const LogBinaryLik& loglik;
  const LogBinaryPri& logpri;
};

class ReparametrizeBinaryAlpha : public McmcReparametrizingBinarySampler {
public:
  ReparametrizeBinaryAlpha(const LogBinaryLik& loglik_, 
                           const LogBinaryPri& logpri_,
                           const double sample_jump_)
    : McmcReparametrizingBinarySampler::McmcReparametrizingBinarySampler(loglik_, logpri_, sample_jump_)
  {}
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const;
};

class ReparametrizeBinaryBetaZ : public McmcReparametrizingBinarySampler {
public:
  ReparametrizeBinaryBetaZ(const LogBinaryLik& loglik_, 
                           const LogBinaryPri& logpri_,
                           const int p_,
                           const double sample_jump_)
    : McmcReparametrizingBinarySampler::McmcReparametrizingBinarySampler(loglik_, logpri_, sample_jump_),
      p(p_)
  {}
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const;
private:
  const int p;
};

class ReparametrizeBinaryTauSq : public McmcReparametrizingBinarySampler {
public:
  ReparametrizeBinaryTauSq(const LogBinaryLik& loglik_, 
                           const LogBinaryPri& logpri_,
                           const int p_,
                           const double sample_jump_)
    : McmcReparametrizingBinarySampler::McmcReparametrizingBinarySampler(loglik_, logpri_, sample_jump_),
      p(p_)
  {}
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const;
private:
  const int p;
};

class ReparametrizeBinaryBetaUGammaX : public McmcReparametrizingBinarySampler {
public:
  ReparametrizeBinaryBetaUGammaX(const LogBinaryLik& loglik_, 
                                 const LogBinaryPri& logpri_,
                                 const double sample_jump_,
                                 const double el2_)
    : McmcReparametrizingBinarySampler::McmcReparametrizingBinarySampler(loglik_, logpri_, sample_jump_),
      el2(el2_)
  {}
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const;
private:
  const double el2;
};

class ReparametrizeBinaryGammaZ : public McmcReparametrizingBinarySampler {
public:
  ReparametrizeBinaryGammaZ(const LogBinaryLik& loglik_, 
                            const LogBinaryPri& logpri_,
                            const int p_,
                            const double sample_jump_)
    : McmcReparametrizingBinarySampler::McmcReparametrizingBinarySampler(loglik_, logpri_, sample_jump_),
      p(p_)
  {}
protected:
  virtual ThetaBinary reparametrize(const ThetaBinary& theta_cur) const;
private:
  const int p;
};

#endif
