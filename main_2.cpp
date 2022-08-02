#include <iostream>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

int 

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  vector<ii> seg;
  vector<ii> pts;
  for (auto i : seg) {
    pts.push_back({i.fi,_});
    pts.push_back({i.se+1,-_});
  }
  sort(pts.begin(),pts.end());
  for (auto i : pts) {
    if (i.se) {
      // buka segment
    }
    else {
      // tutup segment
    }
  }

  --------------------------
  
  set<int> st;

  [_,_,_,_,_,_]_
   ^           ^
  auto it = st.begin()
  it = st.end(); it--;
  int maxi = *it;

  st.erase(_);

  --------------------------

  multiset<int> ms;
  
  [_,_,_,5,5,_]_
   ^           ^
  
  ms.erase(st.find(5));

  --------------------------

  blu_lf
  
  blu_rg

  red_lf = {...}

  red_rg = {...}

  int cnt_seg = 0; // hitung byk segment yang kebuka
  for (auto i : pts) {
    (pos, row, open/close) = i
    if (open) {
      cnt_seg++;
      
      // erase dari red_lf
      // insert ke blu_lf

      // cari segment pasangan
      // erase dari red_rg
      // insert ke blu_rg
    }
    else {
      cnt_seg--;

      if (cnt_seg == 0) {
        // max(blu_lf) < min(red_lf) && max(red_rg) < min(blu_rg)
      }
    }
  }


  return 0;
}