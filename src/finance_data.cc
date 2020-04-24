// Copyright (c) 2020 Eric Jin. All rights reserved.

#include <mylibrary/finance_data.h>

namespace finance {

/**
 * Getters
 */

double FinanceData::Get26WkPriceReturn() const {
  return _26_wk_price_return;
}

double FinanceData::Get3YrRevGrowthRate() const {
  return _3_yr_rev_growth_rate;
}

int FinanceData::GetBuyRec() const {
  return buy_rec;
}

int FinanceData::GetSellRec() const {
  return sell_rec;
}

int FinanceData::GetHoldRec() const {
  return hold_rec;
}

int FinanceData::GetStrongBuyRec() const {
  return strong_buy_rec;
}

int FinanceData::GetStrongSellRec() const {
  return strong_sell_rec;
}

/**
 * Setters
 */

void FinanceData::Set26WkPriceReturn(double _26_wk_price_return_to_set) {
  _26_wk_price_return = _26_wk_price_return_to_set;
}

void FinanceData::Set3YrRevGrowthRate(double _3_yr_rev_growth_rate_to_set) {
  _3_yr_rev_growth_rate = _3_yr_rev_growth_rate_to_set;
}

void FinanceData::SetBuyRec(int buy_rec_to_set) {
  buy_rec = buy_rec_to_set;
}

void FinanceData::SetSellRec(int sell_rec_to_set) {
  sell_rec = sell_rec_to_set;
}

void FinanceData::SetHoldRec(int hold_rec_to_set) {
  hold_rec = hold_rec_to_set;
}

void FinanceData::SetStrongBuyRec(int strong_buy_rec_to_set) {
  strong_buy_rec = strong_buy_rec_to_set;
}

void FinanceData::SetStrongSellRec(int strong_sell_rec_to_set) {
  strong_sell_rec = strong_sell_rec_to_set;
}
}  // namespace mylibrary
