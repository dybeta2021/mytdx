#include "pch.h"
#include "TCalcFuncSets.h"
#include "ma.h"
#include "filter.h"
#include "indicators.h"
#include <iostream>
#include <vector>

////生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定
//
//void TestPlugin1(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
//{
//	for(int i=0;i<DataLen;i++)
//		pfOUT[i]=i;
//}
//
//void TestPlugin2(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
//{
//	for(int i=0;i<DataLen;i++)
//	{
//		pfOUT[i]=pfINa[i]+pfINb[i]+pfINc[i];
//		pfOUT[i]=pfOUT[i]/3;
//	}
//}


void TCalcEMA(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int period = int(*pfINb);
	auto ema = ma::EMA(period);
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = ema.update(pfINa[i]);
	}
}


void TCalcGaussianFilterOneHole(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int period = *pfINb;
	auto gf = filter::GaussianFilterOnePole(period);
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = gf.update(pfINa[i]);
	}
}


void TCalcGaussianFilterTwoHoles(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int period = *pfINb;
	auto gf = filter::GaussianFilterTwoHoles(period);
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = gf.update(pfINa[i]);
	}
}

void TCalcGaussianFilterThreeHoles(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int period = *pfINb;
	auto gf = filter::GaussianFilterThreeHoles(period);
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = gf.update(pfINa[i]);
	}
}

void TCalcGaussianFilterFourHoles(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int period = *pfINb;
	auto gf = filter::GaussianFilterFourHoles(period);
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = gf.update(pfINa[i]);
	}
}

void TCalcSuperSmootherFilter(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	auto ssf = filter::SuperSmootherFilter();
	for (int i = 0; i < DataLen; i++) {
		pfOUT[i] = ssf.update(pfINa[i]);
	}
}


class DataCacheADX {
public:
	static DataCacheADX& getInstance() {
		static DataCacheADX instance;
		return instance;
	}

	void setData(const std::vector<double>& high, const std::vector<double>& low, const std::vector<double>& close) {
		high_ = high;
		low_ = low;
		close_ = close;
	}

	std::vector<double>& getHighData() {
		return high_;
	}

	std::vector<double>& getLowData() {
		return low_;
	}

	std::vector<double>& getCloseData() {
		return close_;
	}

private:
	std::vector<double> high_;
	std::vector<double> low_;
	std::vector<double> close_;

	DataCacheADX() = default;

	DataCacheADX(const DataCacheADX&) = delete;

	DataCacheADX(DataCacheADX&&) = delete;

	DataCacheADX& operator=(const DataCacheADX&) = delete;

	DataCacheADX& operator=(DataCacheADX&&) = delete;
};



void TCalcADX1(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	std::vector<double> high(DataLen);
	std::vector<double> low(DataLen);
	std::vector<double> close(DataLen);
	for (int i = 0; i < DataLen; i++) {
		high[i] = pfINa[i];
		low[i] = pfINb[i];
		close[i] = pfINc[i];
		pfOUT[i] = 0.0;
	}

	auto& cache = DataCacheADX::getInstance();
	cache.setData(high, low, close);
}


void TCalcADX2(int DataLen, float* pfOUT, float* pfINa, float* pfINb, float* pfINc) {
	const int in_size = DataLen;
	const int period = *pfINa;
	auto& cache = DataCacheADX::getInstance();
	std::vector<double>& high = cache.getHighData();
	std::vector<double>& low = cache.getLowData();
	std::vector<double>& close = cache.getCloseData();

	TI_REAL* inputs[] = { high.data(), low.data(), close.data()};
	TI_REAL options[] = { period};
	TI_REAL* outputs[1];
	const int out_size = in_size - ti_adx_start(options);
	outputs[0] = new TI_REAL[out_size];
	const int ret = ti_adx(in_size, inputs, options, outputs);


	for (int i = 0; i < period; i++) {
		pfOUT[i] = 0.0;
	}

	const auto shift_num = in_size - out_size;
	for (int i = period; i < in_size; i++) {
		pfOUT[i] = outputs[0][i - shift_num];
	}
	delete[] outputs[0]; // Free the memory
}




//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&TCalcEMA},
	{2,(pPluginFUNC)&TCalcGaussianFilterOneHole},
	{3,(pPluginFUNC)&TCalcGaussianFilterTwoHoles},
	{4,(pPluginFUNC)&TCalcGaussianFilterThreeHoles},
	{5,(pPluginFUNC)&TCalcGaussianFilterFourHoles},
	{6,(pPluginFUNC)&TCalcSuperSmootherFilter},
	{7,(pPluginFUNC)&TCalcADX1},
	{8,(pPluginFUNC)&TCalcADX2},
	{0,NULL},
};

//导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}
