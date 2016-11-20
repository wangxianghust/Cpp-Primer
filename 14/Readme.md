#exercise 42
count_if(v.cbegin(), v.cend(),std::bind(greater<int>(),_1,1024))
find_if(v.cbegin(), v.cend(), std::bind(not_equal_to<string>(), _1, pooh))
transfrom(v.begin(), v.end(), std::bind(multiplies<int>, _1, 2))
