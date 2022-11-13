#pragma once

#ifndef _colours_hpp
#define _colours_hpp

typedef enum {
    RED = 0,
    GREEN = 1,
    YELLOW = 2,
    BLUE = 3,
    MAGENTA = 4,
    CYAN = 5,
    WHITE = 6,
    BLACK = 7,
    RESET = 8
} colour;

std::map<int, std::string> colours = {
    {0, "RED"},
    {1, "GREEN"},
    {2, "YELLOW"},
    {3, "BLUE"},
    {4, "MAGENTA"},
    {5, "CYAN"},
    {6, "WHITE"},
    {7, "BLACK"},
    {8, "RESET"}
};

std::map<colour, std::string> colourNtoStr = {
    {RED, "\033[31m"},
    {GREEN, "\033[32m"},
    {YELLOW, "\033[33m"},
    {BLUE, "\033[34m"},
    {MAGENTA, "\033[35m"},
    {CYAN, "\033[36m"},
    {WHITE, "\033[37m"},
    {BLACK, "\033[30m"},
    {RESET, "\033[0m"}
};

#endif