#pragma once
#include <cmath>
#include <vector>


namespace ma{
    class EMA {
    private:
        int period_;
        long count_;
        double alpha_;
        double ema_;
        std::vector<double> values_;

    public:
        explicit EMA(const int& period) : period_(period) {
            alpha_ = 2.0 / (period_ + 1.);
            count_ = 0;
            ema_ = 0;
        }


        double update(const double& price) {
            const auto idx = count_++;

            if (idx == 0) {
                ema_ = price;
                values_.push_back(ema_);
                return 0.;
            }
            else if (idx < period_) {
                ema_ = alpha_ * price + (1. - alpha_) * ema_;
                values_.push_back(ema_);
                return 0.;
            }
            else {
                ema_ = alpha_ * price + (1. - alpha_) * ema_;
                values_.push_back(ema_);
                return ema_;
            }
        }

        [[maybe_unused]] auto get_vector() {
            return values_;
        }
    };

}