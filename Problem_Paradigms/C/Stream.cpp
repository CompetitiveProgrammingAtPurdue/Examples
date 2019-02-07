#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
  int id;
  int start;
  int end;
  int rating;
} stream;

bool compare(stream a, stream b) {
  if (a.end < b.end) {
    return true;
  }
  return false;
}

vector<stream> twitch;
vector<int> dp;
vector<int> watch;

//Find the previous stream that doesn't overlap.
int previous(int index) {
  int start = twitch[index].start;
  while (index >= 0) {
    //If the previous ends before or when the next begins, it doesn't overlap.
    if (twitch[index].end <= start) {
      break;
    }
    index--;
  }
  return index;
}

int main() {
  int n;
  cin >> n;
  int i, start, length, rating;
  //Store the streams and calculate end times
  for (i = 0; i < n; i++) {
    cin >> start >> length >> rating;
    twitch.push_back({i, start, start + length, rating});
  }
  stable_sort(twitch.begin(), twitch.end(), compare);
  //Consider watching no streams. This allows us to change what stream we watch first.
  dp.push_back(0);
  //Consider one more stream at a time. Is it worth watching and change what you previously watched?
  for (i = 1; i <= n; i++) {
    //Accesses to twitch will be offset by 1, so accesses to dp can be aligned properly.
    //dp[i] corresponds to the maximum when considering stream 0 through i - 1.
    dp.push_back(max(twitch[i - 1].rating + dp[previous(i - 1) + 1], dp[i - 1]));
  }
  cout << dp[n] << '\n';
  //Now trace back through and find the IDs of the streams to watch.
  i = n;
  while (i > 0) {
    //If you didn't watch this stream, check one stream back.
    if (dp[i] == dp[i - 1]) {
      i--;
    } else {
      //If you watched this stream, check the previous non-overlapping stream.
      watch.push_back(twitch[i - 1].id);
      i = previous(i - 1) + 1;
    }
  }
  //Print the streams to watch in order.
  sort(watch.begin(), watch.end());
  cout << "Watch:\n";
  for (i = 0; i < watch.size(); i++) {
    cout << watch[i] << '\n';
  }
}
