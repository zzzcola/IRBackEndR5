//
// Created by gaome on 2023/7/19.
//

#ifndef IRBACKENDR5_REDUNDANTLOADELIMINATIONOPTIMIZER_H
#define IRBACKENDR5_REDUNDANTLOADELIMINATIONOPTIMIZER_H
#include <set>
#include "IROptimizerBase.h"
namespace MiddleIR::Optimizer
{

class RedundantLoadEliminationOptimizer: public IROptimizerBase
{
public:
    explicit RedundantLoadEliminationOptimizer(const shared_ptr<MiddleIRAST>& irast_):
        IROptimizerBase(irast_)
    {
    }
    virtual void run() override;
};

}   // namespace MiddleIR

#endif   // IRBACKENDR5_REDUNDANTLOADELIMINATIONOPTIMIZER_H