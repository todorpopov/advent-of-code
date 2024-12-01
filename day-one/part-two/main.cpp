#include "iostream"
#include "fstream"
#include "vector"

void readFileAndPopulateInputVectors(std::vector<int>& arrayOne, std::vector<int>& arrayTwo) {
    std::vector<std::string> inputFileVector;

    std::ifstream inputFile("../input.txt");
    std::string s;

    while(getline(inputFile, s)) {
        inputFileVector.push_back(s);
    }

    for(std::string s: inputFileVector) {
        auto pos = s.find("   ");
        int left = stoi(s.substr(0, pos));
        int right = stoi(s.substr(pos + 3, s.length() - 1));

        arrayOne.push_back(left);
        arrayTwo.push_back(right);
    }
}

int result(std::vector<int>& nums1, std::vector<int>& nums2) {
    int result = 0;

    for(int i: nums1) {
        int occ = 0;
        for(int j: nums2) {
            if(i == j) {
                occ++;
            }
        }

        result += i * occ;
    }

    return result;
}

int main(void) {
    std::vector<int> nums1;
    std::vector<int> nums2;

    readFileAndPopulateInputVectors(nums1, nums2);

    std::cout << result(nums1, nums2) << "\n";
}