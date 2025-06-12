#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert> // provides runtime assertions for terminating with an error
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray{
	public:
		static vector<int> get_array() // static function with vector type return value
		// static allows to use class directly from the calling function because static belongs to the class
		{
			return vector<int>{};
		}
};

class TestDataUniqueValues{
	public:
		static vector<int> get_array()
		{
			return vector<int>{1, 2, 3};
		}
		static int	get_expected_result()
		{
			return 0;
		};
};

class TestDataExactlyTwoDifferentMinimums{
	public:
		static vector<int> get_array()
		{
			return vector<int>{2, 1, 5, 1};
		}
		static int	get_expected_result()
		{
			return 1;
		}
};

void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array(); // we call get_array static function directly from the Test...Array class
	// If we used non-static function we would need to create an object based on the class first.
        auto result = minimum_index(seq); // auto automatically deduces the return data type
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);// As soon as condition in brackets is false the program terminates with an error.
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}
