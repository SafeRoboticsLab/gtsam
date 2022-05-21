/* ----------------------------------------------------------------------------

 * GTSAM Copyright 2010, Georgia Tech Research Corporation,
 * Atlanta, Georgia 30332-0415
 * All Rights Reserved
 * Authors: Frank Dellaert, et al. (see THANKS for the full author list)

 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 *  @file HybridDiscreteFactor.h
 *  @date Mar 11, 2022
 *  @author Fan Jiang
 */

#pragma once

#include <gtsam/discrete/DecisionTreeFactor.h>
#include <gtsam/discrete/DiscreteFactor.h>
#include <gtsam/hybrid/HybridFactor.h>

namespace gtsam {

/**
 * A HybridDiscreteFactor is a wrapper for DiscreteFactor, so we hide the
 * implementation of DiscreteFactor, and thus avoiding diamond inheritance.
 */
class HybridDiscreteFactor : public HybridFactor {
 public:
  using Base = HybridFactor;
  using This = HybridDiscreteFactor;
  using shared_ptr = boost::shared_ptr<This>;

  DiscreteFactor::shared_ptr inner;

  // Implicit conversion from a shared ptr of DF
  HybridDiscreteFactor(DiscreteFactor::shared_ptr other);

  // Forwarding constructor from concrete DecisionTreeFactor
  HybridDiscreteFactor(DecisionTreeFactor &&dtf);

 public:
  virtual bool equals(const HybridFactor &lf, double tol) const override;

  void print(
      const std::string &s = "HybridFactor\n",
      const KeyFormatter &formatter = DefaultKeyFormatter) const override;
};
}  // namespace gtsam