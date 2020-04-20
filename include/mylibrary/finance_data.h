// Copyright (c) 2020 [Your Name]. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_


namespace mylibrary {

class FinanceData {
  // Various data received from API call to build geometry:

  // The API updates this value Daily.
  double _26_week_price_return;
  double _3_year_rev_growth_rate_s;

  // Number of recommendations to buy, sell, and hold stock, respectively.
  int buy_rec;
  int sell_rec;
  int hold_rec;

  // Number of recommendations to strongly buy and sell stock, respectively.
  int strong_buy_rec;
  int strong_sell_rec;
};

}  // namespace mylibrary


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
