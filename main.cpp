#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <string>

using namespace std;

void display(uint8_t g[49])
{
    std::string dict[3] = {" ", "O", "X"};
    for (uint8_t i(0); i<7; ++i)
    {
        for (uint8_t j(0); j<7; ++j)
        {
            std::cout << dict[g[7 * i + j]] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool play(uint8_t g[49])
{
    uint8_t c = 0;
    uint8_t g2[49];
    for (uint8_t i(0); i<49; ++i)
    {
        if (g[i] == 1){++c;}
    }
    if (c < 2)
    {
        display(g);
        return 1;
    }
    for (uint8_t i(0); i<49; ++i)
    {
        if (g[i] == 2)
        {
            if (i%7 > 1 && g[i-1] == 1 && g[i-2] == 1)
            {
                for (uint8_t j(0); j<49; ++j){g2[j]=g[j];}
                g2[i] = 1;
                g2[i-1] = 2;
                g2[i-2] = 2;
                if (play(g2))
                {
                    display(g);
                    return 1;
                }
            }
            if (i%7 < 5 && g[i+1] == 1 && g[i+2] == 1)
            {
                for (uint8_t j(0); j<49; ++j){g2[j]=g[j];}
                g2[i] = 1;
                g2[i+1] = 2;
                g2[i+2] = 2;
                if (play(g2))
                {
                    display(g);
                    return 1;
                }
            }
            if (i < 35 && g[i+7] == 1 && g[i+14] == 1)
            {
                for (uint8_t j(0); j<49; ++j){g2[j]=g[j];}
                g2[i] = 1;
                g2[i+7] = 2;
                g2[i+14] = 2;
                if (play(g2))
                {
                    display(g);
                    return 1;
                }
            }
            if (i > 13 and g[i-7] == 1 and g[i-14] == 1)
            {
                for (uint8_t j(0); j<49; ++j){g2[j]=g[j];}
                g2[i] = 1;
                g2[i-7] = 2;
                g2[i-14] = 2;
                if (play(g2))
                {
                    display(g);
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main()
{
    uint8_t grid[49] = {0, 0, 1, 1, 1, 0, 0,
                        0, 1, 1, 1, 1, 1, 0,
                        1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1,
                        0, 1, 1, 1, 1, 1, 0,
                        0, 0, 1, 1, 1, 0, 0};

//    uint8_t grid[49] = {0, 0, 1, 2, 2, 0, 0,
//                        0, 1, 1, 1, 2, 2, 0,
//                        1, 1, 1, 1, 2, 2, 2,
//                        2, 2, 1, 1, 2, 2, 2,
//                        2, 2, 1, 2, 2, 2, 2,
//                        0, 2, 2, 2, 2, 2, 0,
//                        0, 0, 2, 2, 2, 0, 0};

//    uint8_t grid[49] = {0, 0, 1, 1, 1, 0, 0,
//                        0, 1, 1, 1, 1, 1, 0,
//                        1, 1, 1, 1, 1, 1, 1,
//                        1, 1, 1, 1, 1, 1, 1,
//                        1, 1, 1, 1, 1, 1, 1,
//                        0, 1, 1, 1, 1, 1, 0,
//                        0, 0, 1, 1, 1, 0, 0};

//    uint8_t grid[49] = {0, 0, 2, 2, 2, 0, 0,
//                        0, 2, 2, 2, 2, 2, 0,
//                        2, 2, 2, 2, 2, 2, 2,
//                        2, 2, 2, 2, 2, 2, 2,
//                        2, 2, 2, 2, 2, 2, 2,
//                        0, 2, 2, 2, 2, 2, 0,
//                        0, 0, 2, 2, 2, 0, 0};
    play(grid);
}
