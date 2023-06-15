#include <iostream>
#include "indicators.h"

using namespace std;


class DataCacheADX {
public:
    static DataCacheADX &getInstance() {
        static DataCacheADX instance;
        return instance;
    }

    void setData(const std::vector<double> &high, const std::vector<double> &low, const std::vector<double> &close) {
        high_ = high;
        low_ = low;
        close_ = close;
    }

    std::vector<double> &getHighData() {
        return high_;
    }

    std::vector<double> &getLowData() {
        return low_;
    }

    std::vector<double> &getCloseData() {
        return close_;
    }

private:
    std::vector<double> high_;
    std::vector<double> low_;
    std::vector<double> close_;

    DataCacheADX() = default;

    DataCacheADX(const DataCacheADX &) = delete;

    DataCacheADX(DataCacheADX &&) = delete;

    DataCacheADX &operator=(const DataCacheADX &) = delete;

    DataCacheADX &operator=(DataCacheADX &&) = delete;
};

int main() {
    const int in_size = 10;
    {
        auto &cache = DataCacheADX::getInstance();
        std::vector<double> high = {82.15, 81.89, 83.03, 83.30, 83.85, 83.90, 83.33, 84.30, 84.84, 85.00};
        std::vector<double> low = {81.29, 80.64, 81.31, 82.65, 83.07, 83.11, 82.49, 82.30, 84.15, 84.11};
        std::vector<double> close = {81.59, 81.06, 82.87, 83.00, 83.61, 83.15, 82.84, 83.99, 84.55, 84.36};
        cache.setData(high, low, close);
    }

    auto &cache = DataCacheADX::getInstance();
    std::vector<double> &high = cache.getHighData();
    std::vector<double> &low = cache.getLowData();
    std::vector<double> &close = cache.getCloseData();
    auto high1 = high.data();
    auto low1 = low.data();
    auto close1 = close.data();

    std::cout << high1[1] << std::endl;

    TI_REAL *inputs[] = {high1, low1, close1};
    TI_REAL options[] = {5};
    TI_REAL *outputs[1];
    const int out_size = in_size - ti_adx_start(options);
    outputs[0] = new TI_REAL[out_size]; // Use new instead of malloc

    const int ret = ti_adx(in_size, inputs, options, outputs);

    // Print the results
    cout << "Input: ";
    for (int i = 0; i < in_size; ++i) {
        cout << high[i] << ", " << low[i] << ", " << close[i]<<", " <<outputs[0][i] << endl;
    }
    cout << endl;


    cout << "Input: ";
    const auto shift_num = in_size - out_size;
    for (int i = in_size-out_size; i < in_size; ++i) {
        cout << high[i] << ", " << low[i] << ", " << close[i]<<", " <<outputs[0][i-shift_num] << endl;
    }
    cout << endl;
    delete[] outputs[0]; // Free the memory

    return 0;
}
