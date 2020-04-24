// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_


namespace finance {

class FinanceData {
 private:
  // Various data received from API call to build geometry:

  // The API updates this value Daily.
  double _26_wk_price_return;

  double _3_yr_rev_growth_rate;

  // Number of recommendations to buy, sell, and hold stock, respectively.
  int buy_rec;
  int sell_rec;
  int hold_rec;

  // Number of recommendations to strongly buy and sell stock, respectively.
  int strong_buy_rec;
  int strong_sell_rec;

 public:
  // Getters
  double Get26WkPriceReturn() const;
  double Get3YrRevGrowthRate() const;
  int GetBuyRec() const;
  int GetSellRec() const;
  int GetHoldRec() const;
  int GetStrongBuyRec() const;
  int GetStrongSellRec() const;

  // Setters
  void Set26WkPriceReturn(double _26_wk_price_return);
  void Set3YrRevGrowthRate(double _3_yr_rev_growth_rate);
  void SetBuyRec(int buy_rec);
  void SetSellRec(int sell_rec);
  void SetHoldRec(int hold_rec);
  void SetStrongBuyRec(int strong_buy_rec);
  void SetStrongSellRec(int strong_sell_rec);
};

}  // namespace finance


#endif // FINALPROJECT_FINANCE_DATA_H_
