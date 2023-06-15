#pragma once
#include <cmath>
#include <vector>


namespace filter {
    constexpr double M_PI = 3.141592653589793238462643383279502884L;

    class GaussianFilterOnePole {
    private:
        int period_;
        size_t count_;
        double alpha_;
        double beta_;
        double gf1_;
        std::vector<double> values_;

    public:
        explicit GaussianFilterOnePole(const int& period) : period_(period) {
            const auto N = 1;
            const auto omega = 2. * M_PI / period;
            beta_ = (1 - std::cos(omega)) / (std::pow(2, 1. / N) - 1);
            alpha_ = -beta_ + std::sqrt(std::pow(beta_, 2) + 2 * beta_);
            count_ = 0;
            gf1_ = 0;
        }

        double update(const double& val) {
            const auto idx = count_++;

            if (idx == 0) {
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else {
                const auto gf = alpha_ * val + (1 - alpha_) * gf1_;
                gf1_ = gf;
                values_.push_back(gf1_);
                return gf;
            }
        }

        [[maybe_unused]] auto get_vector() {
            return values_;
        }
    };


    class GaussianFilterTwoHoles {
    private:
        int period_;
        size_t count_;
        double alpha_;
        double beta_;
        double gf1_;
        double gf2_;
        std::vector<double> values_;

    public:
        explicit GaussianFilterTwoHoles(const int& period) : period_(period) {
            const auto N = 2;
            const auto omega = 2. * M_PI / period;
            beta_ = (1 - std::cos(omega)) / (std::pow(2, 1. / N) - 1);
            alpha_ = -beta_ + std::sqrt(std::pow(beta_, 2) + 2 * beta_);
            count_ = 0;
            gf1_ = 0;
            gf2_ = 0;
        }

        double update(const double& val) {
            const auto idx = count_++;


            if (idx == 0) {
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 1) {
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else {
                const auto gf = std::pow(alpha_, 2) * val + 2 * (1 - alpha_) * gf1_ - std::pow(1 - alpha_, 2) * gf2_;
                gf2_ = gf1_;
                gf1_ = gf;
                values_.push_back(gf);
                return gf;
            }
        }

        [[maybe_unused]] auto get_vector() {
            return values_;
        }
    };


    class GaussianFilterThreeHoles {
    private:
        int period_;
        size_t count_;
        double alpha_;
        double beta_;
        double gf1_;
        double gf2_;
        double gf3_;
        std::vector<double> values_;

    public:
        explicit GaussianFilterThreeHoles(const int& period) : period_(period) {
            const auto N = 3;
            const auto omega = 2. * M_PI / period;
            beta_ = (1 - std::cos(omega)) / (std::pow(2, 1. / N) - 1);
            alpha_ = -beta_ + std::sqrt(std::pow(beta_, 2) + 2 * beta_);
            count_ = 0;
            gf1_ = 0;
            gf2_ = 0;
            gf3_ = 0;
        }

        double update(const double& val) {
            const auto idx = count_++;

            if (idx == 0) {
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 1) {
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 2) {
                gf3_ = gf2_;
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else {
                const auto gf = std::pow(alpha_, 3) * val + 3 * (1 - alpha_) * gf1_ - 3 * std::pow(1 - alpha_, 2) * gf2_ + std::pow(1 - alpha_, 3) * gf3_;
                gf3_ = gf2_;
                gf2_ = gf1_;
                gf1_ = gf;
                values_.push_back(gf);
                return gf;
            }
        }

        [[maybe_unused]] auto get_vector() {
            return values_;
        }
    };

    class GaussianFilterFourHoles {
    private:
        int period_;
        size_t count_;
        double alpha_;
        double beta_;
        double gf1_;
        double gf2_;
        double gf3_;
        double gf4_;
        std::vector<double> values_;

    public:
        explicit GaussianFilterFourHoles(const int& period) : period_(period) {
            const auto N = 4;
            const auto omega = 2. * M_PI / period;
            beta_ = (1 - std::cos(omega)) / (std::pow(2, 1. / N) - 1);
            alpha_ = -beta_ + std::sqrt(std::pow(beta_, 2) + 2 * beta_);
            count_ = 0;
            gf1_ = 0;
            gf2_ = 0;
            gf3_ = 0;
            gf4_ = 0;
        }

        double update(const double& val) {
            const auto idx = count_++;
            if (idx == 0) {
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 1) {
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 2) {
                gf3_ = gf2_;
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else if (idx == 3) {
                gf4_ = gf3_;
                gf3_ = gf2_;
                gf2_ = gf1_;
                gf1_ = val;
                values_.push_back(val);
                return 0.;
            }
            else {
                const auto gf = std::pow(alpha_, 4) * val + 4 * (1 - alpha_) * gf1_ - 6 * std::pow(1 - alpha_, 2) * gf2_ + 4 * std::pow(1 - alpha_, 3) * gf3_ - std::pow(1 - alpha_, 4) * gf4_;
                gf4_ = gf3_;
                gf3_ = gf2_;
                gf2_ = gf1_;
                gf1_ = gf;
                values_.push_back(gf);
                return gf;
            }
        }

        [[maybe_unused]] auto get_vector() {
            return values_;
        }
    };

    class SuperSmootherFilter {
    private:
        const double SQ2 = 1.41421356237;
        const double A1 = std::exp(-SQ2 * M_PI / 10);
        const double B1 = 2 * A1 * std::cos(SQ2 * 180 / 10);
        const double C2 = B1;
        const double C3 = -A1 * A1;
        const double C1 = 1 - C2 - C3;

        double p2_value_{};
        double p1_value_{};
        double pre_price_{};
        size_t count_{};
        std::vector<double> store_;

    public:
        SuperSmootherFilter() {
            p2_value_ = 0;
            p1_value_ = 0;
            pre_price_ = 0;
            count_ = 0;
        }

        double update(const double& price) {
            const auto idx = count_++;
            double value;
            if (idx == 0) {
                p2_value_ = price;
                pre_price_ = price;
                value = price;
            }
            else if (idx == 1) {
                p1_value_ = price;
                value = price;
            }
            else {
                value = 0.5 * C1 * (price - pre_price_) + C2 * p1_value_ + C3 * p2_value_;
                p2_value_ = p1_value_;
                p1_value_ = value;
                pre_price_ = price;
            }
            store_.push_back(value);
            return value;
        }

        [[maybe_unused]] auto get_vector() {
            return store_;
        }
    };
}