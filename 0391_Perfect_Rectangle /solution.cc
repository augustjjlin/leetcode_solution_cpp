#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <initializer_list>

class Solution {
 public:
    bool isRectangleCover(std::vector<std::vector<int> >& rectangles) {
        // Bottom Left point of Perfect rectangle
        int perfect_X1 = INT_MAX, perfect_Y1 = INT_MAX;
        // Top right point of perfect rectangle
        int perfect_X2 = INT_MIN, perfect_Y2 = INT_MIN;
        // Set to save the record of point
        std::unordered_set<std::string> point_set;
        // Sum of area of rectangles
        int current_area = 0;

        for (auto &rectangle : rectangles) {
            // Get the bottom left and top right point of perfect rectangle
            perfect_X1 = std::min(perfect_X1, rectangle[0]);
            perfect_Y1 = std::min(perfect_Y1, rectangle[1]);
            perfect_X2 = std::max(perfect_X2, rectangle[2]);
            perfect_Y2 = std::max(perfect_Y2, rectangle[3]);

            current_area += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

            SavePointToSet(rectangle, &point_set);
        }

        int perfect_area = (perfect_X2 - perfect_X1) * (perfect_Y2 - perfect_Y1);

        if (perfect_area != current_area) return false;

        if (point_set.size() != 4) return false;

        if (point_set.find(PointToString(perfect_X1, perfect_Y1)) == point_set.end()) {
            return false;
        }

        if (point_set.find(PointToString(perfect_X1, perfect_Y2)) == point_set.end()) {
            return false;
        }

        if (point_set.find(PointToString(perfect_X2, perfect_Y1)) == point_set.end()) {
            return false;
        }

        if (point_set.find(PointToString(perfect_X2, perfect_Y2)) == point_set.end()) {
            return false;
        }

        return true;
    }

    std::string PointToString(int x, int y) {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

    void SavePointToSet(
        const std::vector<int>& rectangle,
        std::unordered_set<std::string>* point_set) {
        for (auto i : {0, 2}) {
            for (auto j : {1, 3}) {
                std::string point = PointToString(rectangle[i], rectangle[j]);

                if ((*point_set).find(point) == (*point_set).end()) {
                    (*point_set).insert(point);
                } else {
                    (*point_set).erase(point);
                }
            }
        }
    }
};
