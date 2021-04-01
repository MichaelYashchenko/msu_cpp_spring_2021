#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <cassert>
#pragma once

using on_start_or_stop = void (*) (void);
using on_number = std::function<void(int)>;
using on_str = std::function<void(const std::string&)>;

class TokenParser
{
private:
    on_number num_callback;
    on_str str_callback;
    on_start_or_stop start_callback;
    on_start_or_stop stop_callback;
public:
    TokenParser() = default;
    void SetStartCallback(on_start_or_stop callback);
    void SetEndCallback(on_start_or_stop callback);
    void SetDigitTokenCallback(on_number callback);
    void SetStringTokenCallback(on_str callback);
    void parse(const std::string& text);
};