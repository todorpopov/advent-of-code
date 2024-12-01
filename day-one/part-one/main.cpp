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

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int result(std::vector<int>& nums1, std::vector<int>& nums2) {
    if(nums1.size() != nums2.size()) {
        return 0;
    }

    int result = 0;
    int i = 0;
    while(i < nums1.size()) {
        if(nums1[i] > nums2[i]) {
            result += nums1[i] - nums2[i];
        }
        
        if(nums2[i] > nums1[i]) {
            result += nums2[i] - nums1[i];
        }

        i++;
    }

    return result;
}

int main(void) {
    std::vector<int> nums1;
    std::vector<int> nums2;

    readFileAndPopulateInputVectors(nums1, nums2);
    mergeSort(nums1, 0, nums1.size());
    mergeSort(nums2, 0, nums2.size());

    std::cout << result(nums1, nums2) << "\n";
}