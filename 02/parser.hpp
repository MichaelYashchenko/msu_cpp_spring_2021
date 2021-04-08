#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <functional>
#include <cassert>

using on_start_or_stop = std::function<void()>;
using on_number = std::function<void(std::uint64_t)>;
using on_str = std::function<void(const std::string&)>;

class TokenParser
{
private:
    on_number num_callback = nullptr;
    on_str str_callback = nullptr;
    on_start_or_stop start_callback = nullptr;
    on_start_or_stop stop_callback = nullptr;
public:
    TokenParser() = default;
    void SetStartCallback(on_start_or_stop callback);
    void SetEndCallback(on_start_or_stop callback);
    void SetDigitTokenCallback(on_number callback);
    void SetStringTokenCallback(on_str callback);
    void parse(const std::string& text);
};