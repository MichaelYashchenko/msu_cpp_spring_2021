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
    if(start_callback){
        start_callback();
    }
    size_t curr_pos = 0;
    while(curr_pos < text.length()){
        size_t offset = 0;
        while(std::isspace(text[curr_pos]) && (curr_pos < text.length())) ++curr_pos;
        while(std::isdigit(text[curr_pos + offset]) && (curr_pos + offset < text.length())){
            ++offset;
        }            
        if(!isdigit(text[curr_pos + offset]) && !std::isspace(text[curr_pos + offset]) && (curr_pos + offset < text.length())){
            while(!std::isspace(text[curr_pos + offset]) && (curr_pos + offset < text.length())){
                ++offset;
            }
            if(str_callback){
                str_callback(text.substr(curr_pos, offset));
            }
        }
        else if((curr_pos + offset <= text.length()) && (offset > 0)){
            try{
                auto tmp = std::stoull(text.substr(curr_pos, offset));
                if(num_callback){
                    num_callback(tmp);
                }
            }
            catch(const std::out_of_range& f){
                if(str_callback){
                    str_callback(text.substr(curr_pos, offset));
            }
            }
        }
		curr_pos += offset;
        
    }
    if(stop_callback){
        stop_callback();
    }
}
