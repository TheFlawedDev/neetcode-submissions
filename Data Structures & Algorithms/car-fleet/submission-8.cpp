class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, double>> res;

    // Iterater over 'n' Cars, calculate their ETA, and place them on a map.
    for (int i = 0; i < position.size(); i++) {
      // The 'eta' will be tied to the car and its position.
      // by placing it on the map in the same order we maintain the 'position'
      // vector original structure.
      double eta = (double)(target - position[i]) / speed[i];

      // the problem states that the elements in the 'position' vector are unique
      // thus we can exclude checking for them and simply place the position as
      // the key and the eta as its value.
      res.push_back({position[i], eta});
    }
    sort(res.begin(), res.end());
    double currentFleetTime = 0;

    int i = res.size() - 1, fleets = 0;
    while (i >= 0) {
      if (res[i].second > currentFleetTime) {
        fleets++;
        currentFleetTime = res[i].second;
      }
      i--;
    }
    return fleets;
  }
};
