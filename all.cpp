#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <map>
#include <cmath>

int Task1 () {
  int n;
  std::cout << "Amount number of elements: ";
  std::cin >> n;

  if (n % 2 != 0) {
    std::cout << "Error: element amount can not be odd" << std::endl;
    return 1;
  }

  std::vector<int> t_arr(n);
  std::cout << "Input your elements: ";
  for (int i = 0; i < n; ++i) {
    std::cin >> t_arr[i];
  }

  // saving iters to V
  std::vector<int> V(t_arr.begin(), t_arr.end());
  // middle anchor
  auto mid = V.begin() + (V.size() / 2);

  std::cout << "Result: ";
  // 2nd half
  for (auto it = mid; it != V.end(); ++it) {
    std::cout << *it << " ";
  }
  // 1st half
  for (auto it = V.begin(); it != mid; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  return 0;
}

std::vector<int> Task2() {
  int size = 0;
  std::cout << "Amount of elements: ";
  std::cin >> size;

  if (size <= 0) {
    return std::vector<int>(); // wrong amount
  }

  std::vector<int> V(size);

  std::cout << "Input elements: ";
  
  // iter here
  for (std::vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
    std::cin >> *it; // straight to pos
  }
  return V;
}

void Task3(std::list<int>& source, std::list<int>& destination) {
  // mid eleemnt
  std::list<int>::iterator mid = source.begin();
  std::advance(mid, source.size() / 2); 

  // move to L2
  destination.splice(destination.end(), source, mid);
}

void Task4() {
  std::string name;
  int K = 1;
  std::cout << "Enter file name: ";
  std::cin >> name;
  std::cout << "Enter K (>0): ";
  if (!(std::cin >> K) || K <= 0) { // check if K is positive
    std::cerr << "Wrong K value.";
    return;
  }
  // file open
  std::ofstream file(name);
  if (!file.is_open()) {
    std::cerr << "Error opening file.";
    return;
  }
  // ostream_iterator
  std::ostream_iterator<char> out_it(file);
  // filln
  std::fill_n(out_it, K, '*');

  std::cout << "Successfully written " << K << " '*'s to file '" << name << "'\n";
}

void Task5(std::deque<int>& D) {
  // find
  auto r_it = std::find(D.rbegin(), D.rend(), 0);
  // found
  if (r_it != D.rend()) {
    D.erase((++r_it).base());
  }
}

void Task6(std::list<int>& L) {
  // mid
  auto mid = L.begin();
  std::advance(mid, L.size() / 2);

  // rbegin_half ....^|.....
  // rend_half ^....|.....
  std::reverse_iterator<std::list<int>::iterator> rbegin_half(mid);
  std::reverse_iterator<std::list<int>::iterator> rend_half(L.begin());

  // copy
  // check by lambda equasion
  std::replace_copy_if(rbegin_half, rend_half, std::back_inserter(L), [](int x) { return x < 0; }, 0);
}

void Task7(std::list<int>& L) {
  // mid
  auto mid = L.begin();
  std::advance(mid, L.size() / 2);

  // evens to start
  std::stable_partition(L.begin(), mid, [](int x) {
    return x % 2 == 0;
  });

  // odds to start
  std::stable_partition(mid, L.end(), [](int x) {
    return x % 2 != 0;
  });
}

void Task8(const std::list<std::string>& L, std::deque<std::string>& D) {
  if (L.empty()) return;
  std::adjacent_difference(
    L.begin(), 
    L.end(), 
    std::back_inserter(D),
    [](const std::string& b, const std::string& a) {
      // a=left, b=right
      std::string result = ""; // element
      if (!a.empty()) result += a.front();
      if (!b.empty()) result += b.back();
      return result;
    }
  );
  // for erasing L[0] from D
  if (!D.empty()) {
    D.erase(D.begin());
  }
}

int Task9(const std::vector<int>& V0, const std::vector<std::vector<int>>& vectors, int n) {
  // multi
  std::multiset<int> ms0(V0.begin(), V0.end());
  int count = 0;

  // vector cycle
  for (int i = 0; i < n; ++i) {
    const auto& VI = vectors[i];
    std::multiset<int> msI(VI.begin(), VI.end());
    // comparsion
    if (std::includes(msI.begin(), msI.end(), ms0.begin(), ms0.end())) {
      count++;
    }
  }
  return count;
}

std::multimap<int, int> Task10(const std::vector<int>& V) { // sth that will look like 1 - 21, 1 - 31, 2 - 12 ...
  std::multimap<int, int> M;
  
  for (std::vector<int>::const_iterator it = V.begin(); it != V.end(); ++it) {
    // find last digit
    int last_digit = std::abs(*it) % 10;
    
    // key + value
    M.insert(std::make_pair(last_digit, *it));
  }
  return M;
}

std::list<int> inputList() {
    int size;
    std::cout << "Введите размер списка: ";
    std::cin >> size;

    std::list<int> L;
    if (size > 0) {
        std::cout << "Введите список: ";
        for (int i = 0; i < size; ++i) {
            int element;
            std::cin >> element;
            L.push_back(element);
        }
    }
    return L;
}

std::list<std::string> inputStringList() {
    int size;
    std::cout << "Введите размер списка: ";
    std::cin >> size;

    std::list<std::string> L;
    if (size > 0) {
        std::cout << "Введите список: ";
        for (int i = 0; i < size; ++i) {
            std::string element;
            std::cin >> element;
            L.push_back(element);
        }
    }
    return L;
}

void insert(std::vector<int>& V) {
  for (std::vector<int>::iterator i = V.begin(); i != V.end(); ) {
    ++i;
    i = V.insert(i, 1);
    ++i;
  }
}
template <typename T> // prints vectors, lists, deques
void print(const T& V) {
  std::cout << "Result: ";
  for (typename T::const_iterator it = V.cbegin(); it != V.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

void multiprint(const std::multimap<int, int>& M) {
  std::cout << "Result(key | value): " << std::endl;
  
  for (std::multimap<int, int>::const_iterator it = M.begin(); it != M.end(); ++it) {
    std::cout << it->first << " | " << it->second << std::endl;
  }
}

int main() {
  std::setlocale(LC_ALL, "Russian");

  int task = 0;
  std::cout << "Номер задания: ";
  std::cin >> task;
  switch (task)
  {
  case 1: {
    Task1();
  }
  case 2: {
    std::vector<int> V = Task2();
    if (V.empty()) {
      std::cout << "Vector is empty or wrong size.";
      return 0;
    }
    insert(V);
    print(V);
    return 0;
  }
  case 3: {
    int ta1[] = {1, 2, 3, 4, 5, 6, 7};
    int ta2[] = {999, 888, 777, 666};
    std::list<int> L1(std::begin(ta1), std::end(ta1));
    std::list<int> L2(std::begin(ta2), std::end(ta2));
    std::cout << "Исходный L1: ";
    print(L1);
    std::cout << "Исходный L2: ";
    print(L2);
    std::cout << "\n";
    // solve
    Task3(L1, L2);
    std::cout << "Измененный L1: ";
    print(L1);
    std::cout << "Измененный L2: ";
    print(L2);
    return 0;
  }
  case 4: {
    Task4();
    return 0;
  }
  case 5: {
    std::deque<int> Q = {1, 2, 3, 4};
    std::cout << "Исходный дек: ";
    print(Q);
    Task5(Q);
    std::cout << "Измененный дек: ";
    print(Q);
    return 0;
  }
  case 6: {
    std::list<int> L = inputList();
    if (L.size() % 2 != 0) {
      std::cout << "Error: element amount can not be odd" << std::endl;
      return 1;
    }
    std::cout << "Исходный список: ";
    print(L);
    Task6(L);
    std::cout << "Измененный список: ";
    print(L);
    return 0;
  }
  case 7: {
    std::list<int> L = inputList();
    if (L.size() % 2 != 0) {
      std::cout << "Error: element amount can not be odd" << std::endl;
      return 1;
    }
    std::cout << "Исходный список: ";
    print(L);
    Task7(L);
    std::cout << "Измененный список: ";
    print(L);
    return 0;
  }
  case 8: {
    std::list<std::string> L = inputStringList();
    std::deque<std::string> D;
    std::cout << "Исходный список: ";
    print(L);
    Task8(L, D);
    std::cout << "Полученный дек: ";
    print(D);
    return 0;
  }
  case 9: {
    std::vector<int> V = Task2();
    if (V.empty()) {
      std::cout << "Vector is empty or wrong size.";
      return 0;
    }
    std::vector<std::vector<int>> vectors = { // +'s for vector {1, 2, 3}
      {1, 2, 4, 5},
      {0, 2, 3, 4, 5},
      {1, 2, 3, 4}, //+
      {2, 2, 1},
      {1, 2, 2, 1, 3, 5}, //+
      {3, 3, 1, 1, 2}, //+
      {1, 2, 2, 4, 5},
      {1},
      {3, 2, 1}, //+
      {3, 1, 1, 1, 1, 2} //+
    };
    int n = 0;
    std::cout << "Введите количество векторов (n <= 10): ";
    std::cin >> n;
    int res = Task9(V, vectors, n);
    std::cout << "Количество подходящих векторов: " << res << std::endl;
    return 0;
  }
  case 10: {
    std::vector<int> V = Task2();
    std::multimap<int, int> M = Task10(V);
    multiprint(M);
    return 0;
  }
  
  default:
    std::cout << "Такого задания нет";
    break;
  }
}