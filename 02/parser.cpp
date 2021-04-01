#include "parser.hpp"


void TokenParser::SetStartCallback(on_start_or_stop callback){
	start_callback = callback;
}

void TokenParser::SetEndCallback(on_start_or_stop callback){
	stop_callback = callback;
}

void TokenParser::SetDigitTokenCallback(on_number callback){
	num_callback = callback;
}

void TokenParser::SetStringTokenCallback(on_str callback){
	str_callback = callback;
}

void TokenParser::parse(const std::string& text){
    if (!(num_callback && str_callback)) return;
    if(start_callback){
        start_callback();
    }
    size_t curr_pos = 0;
    while(curr_pos < text.length()){
        size_t offset = 0;
        while(std::isspace(text[curr_pos])) ++curr_pos;
        if(std::isdigit(text[curr_pos])){
            while(std::isdigit(text[curr_pos + offset])){
                ++offset;
            }
            if(std::isspace(text[curr_pos + offset])){
                auto tmp = std::stoi(text.substr(curr_pos, offset));
                num_callback(tmp);
                curr_pos += offset;
            }else{
                while(!std::isspace(text[curr_pos + offset])){
                    ++offset;
                }
                str_callback(text.substr(curr_pos, offset));
			    curr_pos += offset;
            }
            
        }else{
            while(!std::isspace(text[curr_pos + offset])){
                ++offset;
            }
            str_callback(text.substr(curr_pos, offset));
			curr_pos += offset;
        }
    }
    if(stop_callback){
        stop_callback();
    }
}
