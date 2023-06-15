#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Project  : jupyter 
# @File     : test.py 
# @Author   : yangdong
# @Time     : 2023/6/14 19:16
# @Desc     :


from pickle import load
from pandas import read_pickle, concat
from pycl import calc_bi, calc_duan

raw_data = read_pickle("stock_index_1d.pkl", compression='gzip')
data = raw_data.loc[raw_data["symbol"] == "000300"].copy()
data["bi"] = calc_bi(data["high"].values, data["low"].values)
data["duan"] = calc_duan(data["high"].values, data["low"].values)
data["bi_label"] = data["bi"].abs().cumsum().astype(int)

print(data.loc[data["bi"]!=0])
