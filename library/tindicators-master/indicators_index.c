#include "indicators.h"
const char* ti_version() { return TI_VERSION; }
long int ti_build() { return TI_BUILD; }
int ti_indicator_count() { return TI_INDICATOR_COUNT; }

struct ti_indicator_info ti_indicators[] = {
{"abands", "Acceleration Bands", ti_abands_start, ti_abands, ti_abands_ref, TI_TYPE_INDICATOR, 3, 1, 3, {"high", "low", "close", 0}, {"period", 0}, {"abands_lower", "abands_upper", "abands_middle", 0}, 0, 0, 0},
{"abs", "Vector Absolute Value", ti_abs_start, ti_abs, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"abs", 0}, 0, 0, 0},
{"acos", "Vector Arccosine", ti_acos_start, ti_acos, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"acos", 0}, 0, 0, 0},
{"ad", "Accumulation/Distribution Line", ti_ad_start, ti_ad, 0, TI_TYPE_INDICATOR, 4, 0, 1, {"high", "low", "close", "volume", 0}, {0}, {"ad", 0}, 0, 0, 0},
{"add", "Vector Addition", ti_add_start, ti_add, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"series", "series", 0}, {0}, {"add", 0}, 0, 0, 0},
{"adosc", "Accumulation/Distribution Oscillator", ti_adosc_start, ti_adosc, 0, TI_TYPE_INDICATOR, 4, 2, 1, {"high", "low", "close", "volume", 0}, {"short period", "long period", 0}, {"adosc", 0}, 0, 0, 0},
{"adx", "Average Directional Movement Index", ti_adx_start, ti_adx, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"adx", 0}, 0, 0, 0},
{"adxr", "Average Directional Movement Rating", ti_adxr_start, ti_adxr, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"adxr", 0}, 0, 0, 0},
{"ahma", "Ahrens Moving Average", ti_ahma_start, ti_ahma, ti_ahma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"ahma", 0}, ti_ahma_stream_new, ti_ahma_stream_run, ti_ahma_stream_free},
{"ao", "Awesome Oscillator", ti_ao_start, ti_ao, 0, TI_TYPE_INDICATOR, 2, 0, 1, {"high", "low", 0}, {0}, {"ao", 0}, 0, 0, 0},
{"apo", "Absolute Price Oscillator", ti_apo_start, ti_apo, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"short period", "long period", 0}, {"apo", 0}, 0, 0, 0},
{"aroon", "Aroon", ti_aroon_start, ti_aroon, 0, TI_TYPE_INDICATOR, 2, 1, 2, {"high", "low", 0}, {"period", 0}, {"aroon_down", "aroon_up", 0}, 0, 0, 0},
{"aroonosc", "Aroon Oscillator", ti_aroonosc_start, ti_aroonosc, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"aroonosc", 0}, 0, 0, 0},
{"arsi", "Adaptive Relative Strength Index", ti_arsi_start, ti_arsi, ti_arsi_ref, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"cycpart", 0}, {"arsi", 0}, ti_arsi_stream_new, ti_arsi_stream_run, ti_arsi_stream_free},
{"asin", "Vector Arcsine", ti_asin_start, ti_asin, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"asin", 0}, 0, 0, 0},
{"atan", "Vector Arctangent", ti_atan_start, ti_atan, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"atan", 0}, 0, 0, 0},
{"atr", "Average True Range", ti_atr_start, ti_atr, ti_atr_ref, TI_TYPE_INDICATOR, 3, 1, 1, {"high", "low", "close", 0}, {"period", 0}, {"atr", 0}, ti_atr_stream_new, ti_atr_stream_run, ti_atr_stream_free},
{"avgprice", "Average Price", ti_avgprice_start, ti_avgprice, 0, TI_TYPE_OVERLAY, 4, 0, 1, {"open", "high", "low", "close", 0}, {0}, {"avgprice", 0}, 0, 0, 0},
{"bbands", "Bollinger Bands", ti_bbands_start, ti_bbands, 0, TI_TYPE_OVERLAY, 1, 2, 3, {"series", 0}, {"period", "stddev", 0}, {"bbands_lower", "bbands_middle", "bbands_upper", 0}, 0, 0, 0},
{"bf2", "Butterworth Filter - 2 Poles", ti_bf2_start, ti_bf2, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"bf2", 0}, ti_bf2_stream_new, ti_bf2_stream_run, ti_bf2_stream_free},
{"bf3", "Butterworth Filter - 3 Poles", ti_bf3_start, ti_bf3, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"bf3", 0}, ti_bf3_stream_new, ti_bf3_stream_run, ti_bf3_stream_free},
{"bop", "Balance of Power", ti_bop_start, ti_bop, 0, TI_TYPE_INDICATOR, 4, 0, 1, {"open", "high", "low", "close", 0}, {0}, {"bop", 0}, 0, 0, 0},
{"cci", "Commodity Channel Index", ti_cci_start, ti_cci, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high", "low", "close", 0}, {"period", 0}, {"cci", 0}, 0, 0, 0},
{"ce", "Chandelier Exit", ti_ce_start, ti_ce, ti_ce_ref, TI_TYPE_INDICATOR, 3, 2, 2, {"high", "low", "close", 0}, {"period", "coef", 0}, {"ce_high", "ce_low", 0}, ti_ce_stream_new, ti_ce_stream_run, ti_ce_stream_free},
{"ceil", "Vector Ceiling", ti_ceil_start, ti_ceil, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"ceil", 0}, 0, 0, 0},
{"cmf", "Chaikin Money Flow", ti_cmf_start, ti_cmf, 0, TI_TYPE_INDICATOR, 4, 1, 1, {"high", "low", "close", "volume", 0}, {"period", 0}, {"cmf", 0}, 0, 0, 0},
{"cmi", "Choppy Market Indicator", ti_cmi_start, ti_cmi, ti_cmi_ref, TI_TYPE_INDICATOR, 3, 1, 1, {"high", "low", "close", 0}, {"period", 0}, {"cmi", 0}, ti_cmi_stream_new, ti_cmi_stream_run, ti_cmi_stream_free},
{"cmo", "Chande Momentum Oscillator", ti_cmo_start, ti_cmo, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"cmo", 0}, 0, 0, 0},
{"copp", "Coppock Curve", ti_copp_start, ti_copp, ti_copp_ref, TI_TYPE_INDICATOR, 1, 3, 1, {"series", 0}, {"roc_shorter_period", "roc_longer_period", "wma_period", 0}, {"copp", 0}, ti_copp_stream_new, ti_copp_stream_run, ti_copp_stream_free},
{"cos", "Vector Cosine", ti_cos_start, ti_cos, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"cos", 0}, 0, 0, 0},
{"cosh", "Vector Hyperbolic Cosine", ti_cosh_start, ti_cosh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"cosh", 0}, 0, 0, 0},
{"crossany", "Crossany", ti_crossany_start, ti_crossany, 0, TI_TYPE_MATH, 2, 0, 1, {"series", "series", 0}, {0}, {"crossany", 0}, 0, 0, 0},
{"crossover", "Crossover", ti_crossover_start, ti_crossover, 0, TI_TYPE_MATH, 2, 0, 1, {"series", "series", 0}, {0}, {"crossover", 0}, 0, 0, 0},
{"cvi", "Chaikins Volatility", ti_cvi_start, ti_cvi, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"cvi", 0}, 0, 0, 0},
{"decay", "Linear Decay", ti_decay_start, ti_decay, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"decay", 0}, 0, 0, 0},
{"dema", "Double Exponential Moving Average", ti_dema_start, ti_dema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"dema", 0}, 0, 0, 0},
{"di", "Directional Indicator", ti_di_start, ti_di, 0, TI_TYPE_INDICATOR, 3, 1, 2, {"high", "low", "close", 0}, {"period", 0}, {"plus_di", "minus_di", 0}, 0, 0, 0},
{"div", "Vector Division", ti_div_start, ti_div, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"series", "series", 0}, {0}, {"div", 0}, 0, 0, 0},
{"dm", "Directional Movement", ti_dm_start, ti_dm, 0, TI_TYPE_INDICATOR, 2, 1, 2, {"high", "low", 0}, {"period", 0}, {"plus_dm", "minus_dm", 0}, 0, 0, 0},
{"dpo", "Detrended Price Oscillator", ti_dpo_start, ti_dpo, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"dpo", 0}, 0, 0, 0},
{"dwma", "Double Weighted Moving Average", ti_dwma_start, ti_dwma, ti_dwma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"dwma", 0}, ti_dwma_stream_new, ti_dwma_stream_run, ti_dwma_stream_free},
{"dx", "Directional Movement Index", ti_dx_start, ti_dx, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"dx", 0}, 0, 0, 0},
{"edcf", "Ehlers Distance Coefficient Filter", ti_edcf_start, ti_edcf, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"length", 0}, {"edcf", 0}, ti_edcf_stream_new, ti_edcf_stream_run, ti_edcf_stream_free},
{"edecay", "Exponential Decay", ti_edecay_start, ti_edecay, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"edecay", 0}, 0, 0, 0},
{"ehma", "Exponential Hull Moving Average", ti_ehma_start, ti_ehma, ti_ehma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"ehma", 0}, ti_ehma_stream_new, ti_ehma_stream_run, ti_ehma_stream_free},
{"ema", "Exponential Moving Average", ti_ema_start, ti_ema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"ema", 0}, 0, 0, 0},
{"emsd", "Exponential Moving Standard Deviation", ti_emsd_start, ti_emsd, ti_emsd_ref, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "ma_period", 0}, {"emsd", 0}, ti_emsd_stream_new, ti_emsd_stream_run, ti_emsd_stream_free},
{"emv", "Ease of Movement", ti_emv_start, ti_emv, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high", "low", "volume", 0}, {0}, {"emv", 0}, 0, 0, 0},
{"er", "Efficiency Ratio", ti_er_start, ti_er, ti_er_ref, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"er", 0}, ti_er_stream_new, ti_er_stream_run, ti_er_stream_free},
{"evwma", "Elastic Volume Weighted Moving Average", ti_evwma_start, ti_evwma, ti_evwma_ref, TI_TYPE_OVERLAY, 2, 2, 1, {"close", "volume", 0}, {"period", "gamma", 0}, {"evwma", 0}, ti_evwma_stream_new, ti_evwma_stream_run, ti_evwma_stream_free},
{"exp", "Vector Exponential", ti_exp_start, ti_exp, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"exp", 0}, 0, 0, 0},
{"fi", "Force Index", ti_fi_start, ti_fi, ti_fi_ref, TI_TYPE_INDICATOR, 2, 1, 1, {"close", "volume", 0}, {"period", 0}, {"fi", 0}, ti_fi_stream_new, ti_fi_stream_run, ti_fi_stream_free},
{"fisher", "Fisher Transform", ti_fisher_start, ti_fisher, 0, TI_TYPE_INDICATOR, 2, 1, 2, {"high", "low", 0}, {"period", 0}, {"fisher", "fisher_signal", 0}, 0, 0, 0},
{"floor", "Vector Floor", ti_floor_start, ti_floor, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"floor", 0}, 0, 0, 0},
{"fosc", "Forecast Oscillator", ti_fosc_start, ti_fosc, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"fosc", 0}, 0, 0, 0},
{"frama", "Fractal Adaptive Moving Average", ti_frama_start, ti_frama, 0, TI_TYPE_OVERLAY, 2, 2, 1, {"high", "low", 0}, {"period", "average_period", 0}, {"frama", 0}, ti_frama_stream_new, ti_frama_stream_run, ti_frama_stream_free},
{"gf1", "Gaussian Filter - 1 Pole", ti_gf1_start, ti_gf1, ti_gf1_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"gf1", 0}, ti_gf1_stream_new, ti_gf1_stream_run, ti_gf1_stream_free},
{"gf2", "Gaussian Filter - 2 Poles", ti_gf2_start, ti_gf2, ti_gf2_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"gf2", 0}, ti_gf2_stream_new, ti_gf2_stream_run, ti_gf2_stream_free},
{"gf3", "Gaussian Filter - 3 Poles", ti_gf3_start, ti_gf3, ti_gf3_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"gf3", 0}, ti_gf3_stream_new, ti_gf3_stream_run, ti_gf3_stream_free},
{"gf4", "Gaussian Filter - 4 Poles", ti_gf4_start, ti_gf4, ti_gf4_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"gf4", 0}, ti_gf4_stream_new, ti_gf4_stream_run, ti_gf4_stream_free},
{"hd", "Homodyne Discriminator", ti_hd_start, ti_hd, ti_hd_ref, TI_TYPE_INDICATOR, 1, 0, 1, {"series", 0}, {0}, {"hd", 0}, ti_hd_stream_new, ti_hd_stream_run, ti_hd_stream_free},
{"hf", "Hampel Filter", ti_hf_start, ti_hf, ti_hf_ref, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "threshold", 0}, {"hf", 0}, ti_hf_stream_new, ti_hf_stream_run, ti_hf_stream_free},
{"hfema", "Hampel Filter on Exponential Moving Average", ti_hfema_start, ti_hfema, ti_hfema_ref, TI_TYPE_OVERLAY, 1, 3, 1, {"series", 0}, {"ema_period", "k", "threshold", 0}, {"hfema", 0}, ti_hfema_stream_new, ti_hfema_stream_run, ti_hfema_stream_free},
{"hfsma", "Hampel Filter on Simple Moving Average", ti_hfsma_start, ti_hfsma, ti_hfsma_ref, TI_TYPE_OVERLAY, 1, 3, 1, {"series", 0}, {"sma_period", "k", "threshold", 0}, {"hfsma", 0}, ti_hfsma_stream_new, ti_hfsma_stream_run, ti_hfsma_stream_free},
{"hma", "Hull Moving Average", ti_hma_start, ti_hma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"hma", 0}, 0, 0, 0},
{"hurst", "Hurst Exponent Indicator", ti_hurst_start, ti_hurst, ti_hurst_ref, TI_TYPE_INDICATOR, 1, 1, 2, {"series", 0}, {"period", 0}, {"hurst", "fractal_dim", 0}, ti_hurst_stream_new, ti_hurst_stream_run, ti_hurst_stream_free},
{"hwma", "Henderson asymmetric filter", ti_hwma_start, ti_hwma, ti_hwma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"hwma", 0}, ti_hwma_stream_new, ti_hwma_stream_run, ti_hwma_stream_free},
{"ichi", "Ichimoku", ti_ichi_start, ti_ichi, ti_ichi_ref, TI_TYPE_INDICATOR, 2, 3, 4, {"high", "low", 0}, {"period9", "period26", "period52", 0}, {"ichi_tenkan_sen", "ichi_kijun_sen", "ichi_senkou_span_A", "ichi_senkou_span_B", 0}, ti_ichi_stream_new, ti_ichi_stream_run, ti_ichi_stream_free},
{"idwma", "Inverse Distance Weighted Moving Average", ti_idwma_start, ti_idwma, ti_idwma_ref, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "exponent", 0}, {"idwma", 0}, ti_idwma_stream_new, ti_idwma_stream_run, ti_idwma_stream_free},
{"kama", "Kaufman Adaptive Moving Average", ti_kama_start, ti_kama, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"kama", 0}, 0, 0, 0},
{"kc", "Keltner Channel", ti_kc_start, ti_kc, 0, TI_TYPE_OVERLAY, 3, 2, 3, {"high", "low", "close", 0}, {"period", "multiple", 0}, {"kc_lower", "kc_middle", "kc_upper", 0}, ti_kc_stream_new, ti_kc_stream_run, ti_kc_stream_free},
{"kst", "Know Sure Thing", ti_kst_start, ti_kst, ti_kst_ref, TI_TYPE_INDICATOR, 1, 8, 2, {"series", 0}, {"roc1", "roc2", "roc3", "roc4", "ma1", "ma2", "ma3", "ma4", 0}, {"kst", "kst_signal", 0}, 0, 0, 0},
{"kvo", "Klinger Volume Oscillator", ti_kvo_start, ti_kvo, 0, TI_TYPE_INDICATOR, 4, 2, 1, {"high", "low", "close", "volume", 0}, {"short period", "long period", 0}, {"kvo", 0}, 0, 0, 0},
{"lag", "Lag", ti_lag_start, ti_lag, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"lag", 0}, 0, 0, 0},
{"lf", "Laguerre Filter", ti_lf_start, ti_lf, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"gamma", 0}, {"lf", 0}, ti_lf_stream_new, ti_lf_stream_run, ti_lf_stream_free},
{"linreg", "Linear Regression", ti_linreg_start, ti_linreg, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"linreg", 0}, 0, 0, 0},
{"linregintercept", "Linear Regression Intercept", ti_linregintercept_start, ti_linregintercept, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"linregintercept", 0}, 0, 0, 0},
{"linregslope", "Linear Regression Slope", ti_linregslope_start, ti_linregslope, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"linregslope", 0}, 0, 0, 0},
{"lma", "Leo Moving Average", ti_lma_start, ti_lma, ti_lma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"close", 0}, {"period", 0}, {"lma", 0}, ti_lma_stream_new, ti_lma_stream_run, ti_lma_stream_free},
{"ln", "Vector Natural Log", ti_ln_start, ti_ln, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"ln", 0}, 0, 0, 0},
{"log10", "Vector Base-10 Log", ti_log10_start, ti_log10, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"log10", 0}, 0, 0, 0},
{"macd", "Moving Average Convergence/Divergence", ti_macd_start, ti_macd, 0, TI_TYPE_INDICATOR, 1, 3, 3, {"series", 0}, {"short period", "long period", "signal period", 0}, {"macd", "macd_signal", "macd_histogram", 0}, 0, 0, 0},
{"mama", "MESA Adaptive Moving Average", ti_mama_start, ti_mama, ti_mama_ref, TI_TYPE_OVERLAY, 1, 2, 2, {"series", 0}, {"fastlimit", "slowlimit", 0}, {"mama", "fama", 0}, ti_mama_stream_new, ti_mama_stream_run, ti_mama_stream_free},
{"marketfi", "Market Facilitation Index", ti_marketfi_start, ti_marketfi, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high", "low", "volume", 0}, {0}, {"marketfi", 0}, 0, 0, 0},
{"mass", "Mass Index", ti_mass_start, ti_mass, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high", "low", 0}, {"period", 0}, {"mass", 0}, 0, 0, 0},
{"max", "Maximum In Period", ti_max_start, ti_max, ti_max_ref, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"max", 0}, 0, 0, 0},
{"md", "Mean Deviation Over Period", ti_md_start, ti_md, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"md", 0}, 0, 0, 0},
{"medprice", "Median Price", ti_medprice_start, ti_medprice, 0, TI_TYPE_OVERLAY, 2, 0, 1, {"high", "low", 0}, {0}, {"medprice", 0}, 0, 0, 0},
{"mesastoch", "MESA Stochastic (by John F. Ehlers)", ti_mesastoch_start, ti_mesastoch, ti_mesastoch_ref, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"period", "max_cycle_considered", 0}, {"mesastoch", 0}, ti_mesastoch_stream_new, ti_mesastoch_stream_run, ti_mesastoch_stream_free},
{"mfi", "Money Flow Index", ti_mfi_start, ti_mfi, 0, TI_TYPE_INDICATOR, 4, 1, 1, {"high", "low", "close", "volume", 0}, {"period", 0}, {"mfi", 0}, 0, 0, 0},
{"mgdyn", "McGinley Dynamic", ti_mgdyn_start, ti_mgdyn, ti_mgdyn_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"N", 0}, {"mgdyn", 0}, ti_mgdyn_stream_new, ti_mgdyn_stream_run, ti_mgdyn_stream_free},
{"mhlma", "Middle-High-Low Moving Average", ti_mhlma_start, ti_mhlma, ti_mhlma_ref, TI_TYPE_OVERLAY, 1, 2, 2, {"series", 0}, {"period", "ma_period", 0}, {"mhlsma", "mhlema", 0}, ti_mhlma_stream_new, ti_mhlma_stream_run, ti_mhlma_stream_free},
{"min", "Minimum In Period", ti_min_start, ti_min, ti_min_ref, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"min", 0}, 0, 0, 0},
{"mom", "Momentum", ti_mom_start, ti_mom, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"mom", 0}, 0, 0, 0},
{"msw", "Mesa Sine Wave", ti_msw_start, ti_msw, 0, TI_TYPE_INDICATOR, 1, 1, 2, {"series", 0}, {"period", 0}, {"msw_sine", "msw_lead", 0}, 0, 0, 0},
{"mul", "Vector Multiplication", ti_mul_start, ti_mul, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"series", "series", 0}, {0}, {"mul", 0}, 0, 0, 0},
{"natr", "Normalized Average True Range", ti_natr_start, ti_natr, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high", "low", "close", 0}, {"period", 0}, {"natr", 0}, 0, 0, 0},
{"nvi", "Negative Volume Index", ti_nvi_start, ti_nvi, 0, TI_TYPE_INDICATOR, 2, 0, 1, {"close", "volume", 0}, {0}, {"nvi", 0}, 0, 0, 0},
{"obv", "On Balance Volume", ti_obv_start, ti_obv, 0, TI_TYPE_INDICATOR, 2, 0, 1, {"close", "volume", 0}, {0}, {"obv", 0}, 0, 0, 0},
{"pbands", "Projection Bands", ti_pbands_start, ti_pbands, ti_pbands_ref, TI_TYPE_OVERLAY, 3, 1, 2, {"high", "low", "close", 0}, {"period", 0}, {"pbands_lower", "pbands_upper", 0}, ti_pbands_stream_new, ti_pbands_stream_run, ti_pbands_stream_free},
{"pc", "Price Channel", ti_pc_start, ti_pc, 0, TI_TYPE_OVERLAY, 2, 1, 2, {"high", "low", 0}, {"period", 0}, {"pc_low", "pc_high", 0}, ti_pc_stream_new, ti_pc_stream_run, ti_pc_stream_free},
{"pfe", "Polarized Fractal Efficiency", ti_pfe_start, ti_pfe, ti_pfe_ref, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"period", "ema_period", 0}, {"pfe", 0}, ti_pfe_stream_new, ti_pfe_stream_run, ti_pfe_stream_free},
{"posc", "Projection Oscillator", ti_posc_start, ti_posc, ti_posc_ref, TI_TYPE_INDICATOR, 3, 2, 1, {"high", "low", "close", 0}, {"period", "ema_period", 0}, {"posc", 0}, ti_posc_stream_new, ti_posc_stream_run, ti_posc_stream_free},
{"ppo", "Percentage Price Oscillator", ti_ppo_start, ti_ppo, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"short period", "long period", 0}, {"ppo", 0}, 0, 0, 0},
{"psar", "Parabolic SAR", ti_psar_start, ti_psar, 0, TI_TYPE_OVERLAY, 2, 2, 1, {"high", "low", 0}, {"acceleration factor step", "acceleration factor maximum", 0}, {"psar", 0}, 0, 0, 0},
{"pvi", "Positive Volume Index", ti_pvi_start, ti_pvi, 0, TI_TYPE_INDICATOR, 2, 0, 1, {"close", "volume", 0}, {0}, {"pvi", 0}, 0, 0, 0},
{"pvt", "Price Volume Trend", ti_pvt_start, ti_pvt, ti_pvt_ref, TI_TYPE_INDICATOR, 2, 0, 1, {"close", "volume", 0}, {0}, {"pvt", 0}, ti_pvt_stream_new, ti_pvt_stream_run, ti_pvt_stream_free},
{"pwma", "Power Weighted Moving Average", ti_pwma_start, ti_pwma, ti_pwma_ref, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "power", 0}, {"pwma", 0}, ti_pwma_stream_new, ti_pwma_stream_run, ti_pwma_stream_free},
{"qstick", "Qstick", ti_qstick_start, ti_qstick, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"open", "close", 0}, {"period", 0}, {"qstick", 0}, 0, 0, 0},
{"rema", "Regularized Exponential Moving Average", ti_rema_start, ti_rema, 0, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "lambda", 0}, {"rema", 0}, ti_rema_stream_new, ti_rema_stream_run, ti_rema_stream_free},
{"rmf", "Recursive Median Filter", ti_rmf_start, ti_rmf, 0, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"critical_period", "median_period", 0}, {"rmf", 0}, ti_rmf_stream_new, ti_rmf_stream_run, ti_rmf_stream_free},
{"rmi", "Relative Momentum Index", ti_rmi_start, ti_rmi, ti_rmi_ref, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"period", "lookback_period", 0}, {"rmi", 0}, ti_rmi_stream_new, ti_rmi_stream_run, ti_rmi_stream_free},
{"rmta", "Recursive Moving Trend Average", ti_rmta_start, ti_rmta, 0, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "beta", 0}, {"rmta", 0}, 0, 0, 0},
{"roc", "Rate of Change", ti_roc_start, ti_roc, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"roc", 0}, 0, 0, 0},
{"rocr", "Rate of Change Ratio", ti_rocr_start, ti_rocr, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"rocr", 0}, 0, 0, 0},
{"roof", "The Roofing Filter", ti_roof_start, ti_roof, 0, TI_TYPE_OVERLAY, 1, 0, 1, {"series", 0}, {0}, {"roof", 0}, ti_roof_stream_new, ti_roof_stream_run, ti_roof_stream_free},
{"round", "Vector Round", ti_round_start, ti_round, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"round", 0}, 0, 0, 0},
{"rsi", "Relative Strength Index", ti_rsi_start, ti_rsi, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"rsi", 0}, 0, 0, 0},
{"rvi", "Relative Volatility Index", ti_rvi_start, ti_rvi, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"ema_period", "stddev_period", 0}, {"rvi", 0}, ti_rvi_stream_new, ti_rvi_stream_run, ti_rvi_stream_free},
{"shmma", "Sharp Modified Moving Average", ti_shmma_start, ti_shmma, ti_shmma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"shmma", 0}, ti_shmma_stream_new, ti_shmma_stream_run, ti_shmma_stream_free},
{"sin", "Vector Sine", ti_sin_start, ti_sin, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"sin", 0}, 0, 0, 0},
{"sinh", "Vector Hyperbolic Sine", ti_sinh_start, ti_sinh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"sinh", 0}, 0, 0, 0},
{"sma", "Simple Moving Average", ti_sma_start, ti_sma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"sma", 0}, ti_sma_stream_new, ti_sma_stream_run, ti_sma_stream_free},
{"smi", "Stochastic Momentum Index", ti_smi_start, ti_smi, ti_smi_ref, TI_TYPE_INDICATOR, 3, 3, 1, {"high", "low", "close", 0}, {"q_period", "r_period", "s_period", 0}, {"smi", 0}, ti_smi_stream_new, ti_smi_stream_run, ti_smi_stream_free},
{"sqrt", "Vector Square Root", ti_sqrt_start, ti_sqrt, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"sqrt", 0}, 0, 0, 0},
{"ssmooth", "SuperSmoother Filter", ti_ssmooth_start, ti_ssmooth, 0, TI_TYPE_OVERLAY, 1, 0, 1, {"series", 0}, {0}, {"ssmooth", 0}, ti_ssmooth_stream_new, ti_ssmooth_stream_run, ti_ssmooth_stream_free},
{"stddev", "Standard Deviation Over Period", ti_stddev_start, ti_stddev, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"stddev", 0}, 0, 0, 0},
{"stderr", "Standard Error Over Period", ti_stderr_start, ti_stderr, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"stderr", 0}, 0, 0, 0},
{"stoch", "Stochastic Oscillator", ti_stoch_start, ti_stoch, 0, TI_TYPE_INDICATOR, 3, 3, 2, {"high", "low", "close", 0}, {"k period", "k slowing period", "d period", 0}, {"stoch_k", "stoch_d", 0}, 0, 0, 0},
{"stochrsi", "Stochastic RSI", ti_stochrsi_start, ti_stochrsi, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"stochrsi", 0}, 0, 0, 0},
{"sub", "Vector Subtraction", ti_sub_start, ti_sub, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"series", "series", 0}, {0}, {"sub", 0}, 0, 0, 0},
{"sum", "Sum Over Period", ti_sum_start, ti_sum, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"sum", 0}, 0, 0, 0},
{"swma", "Sine Weighted Moving Average", ti_swma_start, ti_swma, ti_swma_ref, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"swma", 0}, ti_swma_stream_new, ti_swma_stream_run, ti_swma_stream_free},
{"t3", "T3 Moving Average", ti_t3_start, ti_t3, ti_t3_ref, TI_TYPE_OVERLAY, 1, 2, 1, {"series", 0}, {"period", "v", 0}, {"t3", 0}, ti_t3_stream_new, ti_t3_stream_run, ti_t3_stream_free},
{"tan", "Vector Tangent", ti_tan_start, ti_tan, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"tan", 0}, 0, 0, 0},
{"tanh", "Vector Hyperbolic Tangent", ti_tanh_start, ti_tanh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"tanh", 0}, 0, 0, 0},
{"tema", "Triple Exponential Moving Average", ti_tema_start, ti_tema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"tema", 0}, 0, 0, 0},
{"todeg", "Vector Degree Conversion", ti_todeg_start, ti_todeg, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"degrees", 0}, 0, 0, 0},
{"torad", "Vector Radian Conversion", ti_torad_start, ti_torad, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"radians", 0}, 0, 0, 0},
{"tr", "True Range", ti_tr_start, ti_tr, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high", "low", "close", 0}, {0}, {"tr", 0}, 0, 0, 0},
{"trima", "Triangular Moving Average", ti_trima_start, ti_trima, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"trima", 0}, 0, 0, 0},
{"trix", "Trix", ti_trix_start, ti_trix, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"trix", 0}, 0, 0, 0},
{"trunc", "Vector Truncate", ti_trunc_start, ti_trunc, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"series", 0}, {0}, {"trunc", 0}, 0, 0, 0},
{"tsf", "Time Series Forecast", ti_tsf_start, ti_tsf, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"tsf", 0}, 0, 0, 0},
{"tsi", "True Strength Index", ti_tsi_start, ti_tsi, ti_tsi_ref, TI_TYPE_INDICATOR, 1, 2, 1, {"series", 0}, {"y_period", "z_period", 0}, {"tsi", 0}, ti_tsi_stream_new, ti_tsi_stream_run, ti_tsi_stream_free},
{"typprice", "Typical Price", ti_typprice_start, ti_typprice, 0, TI_TYPE_OVERLAY, 3, 0, 1, {"high", "low", "close", 0}, {0}, {"typprice", 0}, 0, 0, 0},
{"ultosc", "Ultimate Oscillator", ti_ultosc_start, ti_ultosc, 0, TI_TYPE_INDICATOR, 3, 3, 1, {"high", "low", "close", 0}, {"short period", "medium period", "long period", 0}, {"ultosc", 0}, 0, 0, 0},
{"var", "Variance Over Period", ti_var_start, ti_var, 0, TI_TYPE_MATH, 1, 1, 1, {"series", 0}, {"period", 0}, {"var", 0}, 0, 0, 0},
{"vhf", "Vertical Horizontal Filter", ti_vhf_start, ti_vhf, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"vhf", 0}, 0, 0, 0},
{"vi", "Vortex Indicator", ti_vi_start, ti_vi, ti_vi_ref, TI_TYPE_INDICATOR, 3, 1, 2, {"high", "low", "close", 0}, {"period", 0}, {"vi_p", "vi_m", 0}, ti_vi_stream_new, ti_vi_stream_run, ti_vi_stream_free},
{"vidya", "Variable Index Dynamic Average", ti_vidya_start, ti_vidya, 0, TI_TYPE_OVERLAY, 1, 3, 1, {"series", 0}, {"short period", "long period", "alpha", 0}, {"vidya", 0}, 0, 0, 0},
{"volatility", "Annualized Historical Volatility", ti_volatility_start, ti_volatility, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"series", 0}, {"period", 0}, {"volatility", 0}, 0, 0, 0},
{"vosc", "Volume Oscillator", ti_vosc_start, ti_vosc, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"volume", 0}, {"short period", "long period", 0}, {"vosc", 0}, 0, 0, 0},
{"vwap", "Volume Weighted Average Price", ti_vwap_start, ti_vwap, ti_vwap_ref, TI_TYPE_OVERLAY, 4, 1, 1, {"high", "low", "close", "volume", 0}, {"period", 0}, {"vwap", 0}, ti_vwap_stream_new, ti_vwap_stream_run, ti_vwap_stream_free},
{"vwma", "Volume Weighted Moving Average", ti_vwma_start, ti_vwma, 0, TI_TYPE_OVERLAY, 2, 1, 1, {"close", "volume", 0}, {"period", 0}, {"vwma", 0}, 0, 0, 0},
{"wad", "Williams Accumulation/Distribution", ti_wad_start, ti_wad, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high", "low", "close", 0}, {0}, {"wad", 0}, 0, 0, 0},
{"wcprice", "Weighted Close Price", ti_wcprice_start, ti_wcprice, 0, TI_TYPE_OVERLAY, 3, 0, 1, {"high", "low", "close", 0}, {0}, {"wcprice", 0}, 0, 0, 0},
{"wilders", "Wilders Smoothing", ti_wilders_start, ti_wilders, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"wilders", 0}, 0, 0, 0},
{"willr", "Williams %R", ti_willr_start, ti_willr, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high", "low", "close", 0}, {"period", 0}, {"willr", 0}, 0, 0, 0},
{"wma", "Weighted Moving Average", ti_wma_start, ti_wma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"wma", 0}, 0, 0, 0},
{"zlema", "Zero-Lag Exponential Moving Average", ti_zlema_start, ti_zlema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"series", 0}, {"period", 0}, {"zlema", 0}, 0, 0, 0},
{0,0,0,0,0,0,0,0,0,{0,0},{0,0},{0,0},0,0,0}
};
int ti_stream_run(ti_stream *stream, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs) {
    return ti_indicators[stream->index].stream_run(stream, size, inputs, outputs);
}

ti_indicator_info *ti_stream_get_info(ti_stream *stream) {
    return ti_indicators + stream->index;
}

int ti_stream_get_progress(ti_stream *stream) {
    return stream->progress;
}

void ti_stream_free(ti_stream *stream) {
    ti_indicators[stream->index].stream_free(stream);
}

const ti_indicator_info *ti_find_indicator(const char *name) {
    int imin = 0;
    int imax = sizeof(ti_indicators) / sizeof(ti_indicator_info) - 2;

    /* Binary search */
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        const int c = strcmp(name, ti_indicators[i].name);
        if (c == 0) {
            return ti_indicators + i;
        } else if (c > 0) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }

    return 0;
}