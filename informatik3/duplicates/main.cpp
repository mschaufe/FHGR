#include <iostream>
#include <vector>

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main() {
    std::vector<int> v = {3,1,1,2,1,3,3,3,1,5,1};
    std::vector<int> output ={};
    for (size_t i = 0; i<v.size();i++){
        bool found = false;
        for (size_t s = 0; s<output.size();s++){
            if (v[i]== output[s]){
                found = true;
                break;
            }
        }
        if (!found){
            output.push_back(v[i]);
        }
    }
    print(v);
    printf("\n");
    print(output);

    return 0;
}