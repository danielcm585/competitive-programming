Struktur Data Dasar

> Vector -> dynamic array

> Queue -> FIFO

queue<int> q;

|
| 3 4
|

q.push(5);
q.push(3);
q.push(4);
q.pop();
q.front(); // 3
q.size(); // 2
q.empty(); // false

> Stack -> LIFO

stack<string> s;

 hai
 halo
______

s.push("halo")
s.push("hai")
s.push("dunia")
s.top(); // "dunia"
s.pop();
s.size(); // 2
s.empty(); // false

> Deque -> Double Ended Queue

deque<int> s;

[]

s.push_back()
s.push_front()
s.back();
s.front();
s.pop_back();
s.pop_front();
s.size();
s.empty();