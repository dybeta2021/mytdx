#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "tdxCL.h"
#include <vector>
#include <algorithm>

namespace py = pybind11;


///
/// \param high
/// \param low
/// \return
std::vector<double> calc_bi(const std::vector<double> &high,
                            const std::vector<double> &low) {
    const int count = static_cast<int>(high.size());
    auto *pHigh = new float[high.size()];
    std::transform(high.begin(), high.end(), pHigh, [](double d) { return static_cast<float>(d); });
    auto *pLow = new float[low.size()];
    std::transform(low.begin(), low.end(), pLow, [](double d) { return static_cast<float>(d); });
    auto *pOut = new float[high.size()]();

    Bi2(count, pOut, nullptr, pHigh, pLow);
    std::vector<double> out(high.size());
    std::transform(pOut, pOut + high.size(), out.begin(), [](float f) { return static_cast<double>(f); });

    // 释放动态分配的内存
    delete[] pHigh;
    delete[] pLow;
    delete[] pOut;
    return out;
}


///
/// \param high
/// \param low
/// \return
std::vector<double> calc_duan(const std::vector<double> &high,
                              const std::vector<double> &low) {
    const int count = static_cast<int>(high.size());
    auto *pHigh = new float[high.size()];
    std::transform(high.begin(), high.end(), pHigh, [](double d) { return static_cast<float>(d); });
    auto *pLow = new float[low.size()];
    std::transform(low.begin(), low.end(), pLow, [](double d) { return static_cast<float>(d); });
    const auto bi = calc_bi(high, low);
    auto *pBi = new float[low.size()];
    std::transform(bi.begin(), bi.end(), pBi, [](double d) { return static_cast<float>(d); });
    auto *pOut = new float[high.size()]();

    Duan0(count, pOut, pBi, pHigh, pLow);
    std::vector<double> out(high.size());
    std::transform(pOut, pOut + high.size(), out.begin(), [](float f) { return static_cast<double>(f); });

    // 释放动态分配的内存
    delete[] pHigh;
    delete[] pLow;
    delete[] pBi;
    delete[] pOut;
    return out;
}


// 定义一个模块，将辅助函数导出为Python函数
PYBIND11_MODULE(pycl, m) {
    m.doc() = "pybind11 example plugin";// optional module docstring

    m.def("calc_bi", &calc_bi, "A function that calculates bi values from high and low vectors",
          py::arg("high"), py::arg("low"));

    m.def("calc_duan", &calc_duan, "A function that calculates duan values from high and low vectors",
          py::arg("high"), py::arg("low"));
}