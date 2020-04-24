// Copyright (c) 2020 Eric Jin. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_


namespace finance {

class FinanceData {
 private:
  // Various data received from API call to build geometry:
  double price_quote;

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
  double GetPriceQuote() const;
  double Get26WkPriceReturn() const;
  double Get3YrRevGrowthRate() const;
  int GetBuyRec() const;
  int GetSellRec() const;
  int GetHoldRec() const;
  int GetStrongBuyRec() const;
  int GetStrongSellRec() const;

  // Setters
  void SetPriceQuote(double price_quote_to_set);
  void Set26WkPriceReturn(double _26_wk_price_return_to_set);
  void Set3YrRevGrowthRate(double _3_yr_rev_growth_rate_to_set);
  void SetBuyRec(int buy_rec_to_set);
  void SetSellRec(int sell_rec_to_set);
  void SetHoldRec(int hold_rec_to_set);
  void SetStrongBuyRec(int strong_buy_rec_to_set);
  void SetStrongSellRec(int strong_sell_rec_to_set);
};

}  // namespace finance


#endif // FINALPROJECT_FINANCE_DATA_H_
