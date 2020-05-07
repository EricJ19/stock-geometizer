# Stock Geometizer

Author: Eric Jin

####Project Summary:

For my final project, I intend to create a data visualization app to analyze and compare stocks. The current vision is
to allow the user to specify a particular stock to the app and in response the app will produce a geometric shape. This
shape is specified based on information on the stock such as "26 Week Price Daily Return", number of recommendations to
buy this stock by analysts etc. For instance, a stock with a large number of recommendations may appear with a darker shade
of green where a stock with a lower number of recommendations will appear more red. Another example is, this shape
can have more edges if, say the average return over some time is higher. Additionally, there can be up to 3 stocks the
user can choose to visually compare the geometric shapes and colors of the stocks side by side. There may be more direct
analysis of the stock (ex. The Number of Recommendations for the Stock is: 56) depicted alongside the data visualization.

####Interest:

Personally, I enjoy the subjects of economics and finance and have taken several courses in economics from high school
and university. In addition, when messing about with Cinder in the "Snake" CS126 assignment, I found myself enjoying and
experimenting with shapes. Thus, I feel interested in developing a data visualization tool in the realm of economics 
and finance.

####Libraries and API:

I will use the API by [Finnhub](https://finnhub.io/docs/api#quote). Specifically, I will use their API for get requests
for things like stock prices and other details to analyze the stock. To simplify requesting data from the API, I will
use [libcurl](https://curl.haxx.se/libcurl/) library and it's wrapper library 
[C++Requests](https://whoshuu.github.io/cpr/) to support getting data from the API. Additionally, I will use
[OpenSSL](https://www.openssl.org/) to support API calls. Moreover, [nlohmann/json](https://github.com/nlohmann/json) is
used to parse JSON response from the API. Additionally, I will use [ImGui](https://github.com/simongeilfus/Cinder-ImGui)
 to read user inputs for the API calls.

####Timline:
By the end of week 1 I aim to incorporate the library complete the logic for the get requests from the API 
and translating them into geometric shapes. By the end of week 2 I aim to complete the user interface and the processing 
of custom stock inputs by the user. By the end of week 3 I aim to complete other features of the app such as selecting
multiple stocks and troubleshooting issues.

####Extensions:
If I have time, I can add features related to background music. Also, I can try to extend the data visualization to more
than just stocks to, for instance, certain financial indexes. So the app would create an index and show a 
geometric visualization
based on features of that index.

---

