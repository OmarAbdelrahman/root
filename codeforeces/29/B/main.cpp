#include <bits/stdc++.h>
using namespace std;

int main() {
  double ab_dist, atraffic_dist, v, g, r;
  cin >> ab_dist >> atraffic_dist >> v >> g >> r;
  double to_traffic_time = atraffic_dist / v;
  if (to_traffic_time < g) {
    cout << fixed << ab_dist / v << endl;
  } else {
    double time_left_to_green = fabs(fmod(to_traffic_time, g + r) - (g + r));
    cout << fixed << to_traffic_time + time_left_to_green + ((ab_dist - atraffic_dist) / v) << endl;
  }
  return 0;
}
