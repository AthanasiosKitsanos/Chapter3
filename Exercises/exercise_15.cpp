#include "headers.h"

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(1, 100);

    std::vector<int> vec;

    for(int i = 0; i < 100; i += 2)
    {
        vec.push_back(dist(gen));
        vec.push_back(dist(gen));
    }

    std::unordered_map<int, int> freq;

    for(int num: vec)
    {
        freq[num]++;
    }

    int mode_count = 0;
    int mode_number = 0;

    for(const std::pair<const int, int>& p : freq)
    {
        if(p.second > mode_count)
        {
            mode_count = p.second;
            mode_number = p.first;
        }   
    }
        
    std::cout << "Mode: " << mode_count << '\t' << "Number: " << mode_number << std::endl;

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0 ;
}