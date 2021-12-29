#include <iostream>
#include <vector>
#include <cstring>
// #include <cctype>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double PI {3.141593};

// Function prototype
double calc_area_circle(double);
double calc_vol_cylinder(double, double);
void area_circle();
void volume_cylinder();
double calc_cost(double, double tax_rate=0.06, double shipping=2.5);
int add_nums(int, int);
double add_nums(double, double);
void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int val);
void swap(int &, int &);
void print_vec(const vector<int> &);
unsigned long long fib(unsigned long long);
void var_scope();

int main() {
    /*
    ========, int val================= CPP array =========================
    */
    // int test_score [5] {100. 95, 99, 98, 97};
    // int tmp[123] {0};
   
    // char vowels[] {'a', 'e', 'i', 'o', 'u'};
    // cout << "The first vowel is: " << vowels[0] << endl;
    // cout << "The last vowel is: " << vowels[4] << endl;

    // // always initialize to 0
    // int score[5] {0};
    // for (size_t i = 0; i < 5; i++) {
    //     score[i] = i * 10;
    //     cout << "The " << i << " element is " << score[i] << endl;
    // }

    // // cout << "value of the array name: " << score << endl;
    // // for (size_t i = 0; i < 5; i++) {
    // //     cout << "The " << i << " element is " << *(score + i) << endl;
    // // }
    // const int rows {3};
    // const int cols {4};
    // int movie_rating [rows][cols] {0};

    // for (size_t i = 0; i < rows; i++) {
    //     for (size_t j = 0; j < cols; j++) {
    //         movie_rating[i][j] = (i + 1)*(j + 1);
    //         cout << "(" << i << ", " << j << "): " << movie_rating[i][j] << endl;
    //     }
    // }
    /*
    ========================= CPP vector =========================
    */
    // vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    // vector <int> score (10);
    // cout << vowels.at(1) << endl;
    // vowels.push_back('x');
    // cout << vowels.at(5) << endl;
    // cout << vowels.size() << endl;

    // vector <vector <int>> movie_rating {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12}
    // };

    // cout << movie_rating.at(1).at(0) << endl;
    // vector <int> vector1;
    // vector <int> vector2;

    // vector1.push_back(10);
    // vector1.push_back(20);

    // vector2.push_back(100);
    // vector2.push_back(200);

    // for (size_t i = 0; i < vector1.size(); i++) {
    //     cout << i << ": " << vector1.at(i) << endl;
    // }

    // vector <vector <int>> vector_2d;
    // vector_2d.push_back(vector1);
    // vector_2d.push_back(vector2);

    // for (size_t i = 0; i < vector_2d.size(); i++) {
    //     for (size_t j = 0; j < vector_2d.at(0).size(); j++) {
    //         cout << "(" << i << ", " << j << "): "<< vector_2d.at(i).at(j) << endl;
    //     }
    // }

    // vector1.at(0) = 1000;
    // for (size_t i = 0; i < vector1.size(); i++) {
    //     cout << i << ": " << vector1.at(i) << endl;
    // }

    // for (size_t i = 0; i < vector_2d.size(); i++) {
    //     for (size_t j = 0; j < vector_2d.at(0).size(); j++) {
    //         cout << "(" << i << ", " << j << "): "<< vector_2d.at(i).at(j) << endl;
    //     }
    // }

    // char first_name[20] {};
    // char last_name[20] {};
    // char full_name[50] {};
    // char temp[50] {};

    // cout << "Enter your first name and last name: ";
    // cin >> first_name;
    // cin >> last_name;
    // cout << first_name << strlen(first_name) << endl;
    // cout << last_name << strlen(last_name) << endl;

    // strcpy(full_name, first_name);
    // strcat(full_name, " ");
    // strcat(full_name, last_name);

    // cout << "Your full name is: " <<full_name << endl;

    // // cout << "Enter your full name: ";
    // // cin.getline(full_name, 50)
    // // cout << "Your full name is: " <<full_name << endl;

    // for (size_t i = 0; i < strlen(full_name); i++)
    //     if (isalpha(full_name[i]))
    //         full_name[i] = toupper(full_name[i]);

    // cout << "Your full name is: " <<full_name << endl;

    // string s1;
    // string s2 {"aoao"};
    // string s3 (3, 'X');
    // string s4 {s2, 0, 3};
 
    // cout << "s2: " << s2 << " s3: " << s3 << " s4: " << s4 << endl;

    // s1 = "XGIYUHJNKL";
    // s2 = s1;
    // cout << "s2: " << s2 << " with length " << s2.length() << endl;
    // for (char c: s1) {
    //     cout << c;
    // }
    // cout << endl;

    // for (size_t i = 0; i < s1.length(); i++)
    // {
    //     cout << s1.at(i);
    // }
    // cout << endl;

    // s1.erase(0, 3);
    // cout << "s1 is now: " << s1 << endl;

    // s1 = "The secret word is Boo";
    // size_t r = s1.find("Boo");
    // if (r != string::npos)
    // {
    //     cout << r << endl;
    // }

    // int random_number {};
    // size_t cnt {10};
    // int min {1}, max {6};

    // cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
    // for (size_t i = 0; i < cnt; ++i) {
    //     random_number = rand() % max + min;
    //     cout << random_number << endl;
    // }

    /*
    ======================== CPP functions ========================
    */

    // area_circle();
    // volume_cylinder();
    // double cost {};
    // cost = calc_cost(100.);
    // cout << "The cost with default tax rate is " << cost << endl;
    // cost = calc_cost(100., 0.08);
    // cout << "The cost with 0.08 tax rate is " << cost << endl;
    // int a = add_nums(1, 2);
    // double b = add_nums(1.1, 2.2);
    // cout << a << endl;
    // cout << b << endl;
    // int nums [] {1, 2, 3, 4, 5};
    // print_array(nums, 5);
    // set_array(nums, 5, 100);
    // print_array(nums, 5);
    // int x {10}, y {20};
    // cout << "x: " << x << " y: " << y << endl;
    // swap(x, y);
    // cout << "x: " << x << " y: " << y << endl;
    // vector<int> vec {1, 2, 3, 4, 5};
    // print_vec(vec);
    // cout << "The fibonacci number of 30 is: " << fib(30) << endl;
    // return 0;

    // int i {1};
    // cout << "main: i = " << i << endl;

    // var_scope();
    // cout << "main: i = " << i << endl;
    // var_scope();
    // cout << "main: i = " << i << endl;
    // var_scope();
    // cout << "main: i = " << i << endl;
    double *ptr {nullptr};
    size_t i {0};
    cout << "how many elements: ";
    cin >> i;
    ptr = new double[i];
    cout << ptr << endl;
    delete [] ptr;
    return 0;
}

double calc_area_circle(double radius) {
    return PI * radius * radius;
}

double calc_vol_cylinder(double radius, double height) {
    return calc_area_circle(radius) * height;
}

void area_circle() {
    double rad {};
    cout << "\nEnter the radius of the circle: ";
    cin >> rad;
    cout << "The area of a circle with radius " << rad;
    cout << " is " << calc_area_circle(rad) << endl;
}

void volume_cylinder() {
    double rad {};
    double h {};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> rad;
    cout << "\nEnter the height of the cylinder: ";
    cin >> h;
    cout << "The volumn of a cylinder with radius " << rad << " and height " << h;
    cout << " is " << calc_vol_cylinder(rad, h) << endl;
}

double calc_cost(double cost, double tax_rate, double shipping) {
    return  cost * (1 + tax_rate) + shipping;
}

int add_nums(int a, int b) {
    return a + b;
}

double add_nums(double a, double b) {
    return a + b;
}

void print_array(const int arr[], size_t size) {
    for (size_t i {0}; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void set_array(int arr[], size_t size, int val) {
    for (size_t i {0}; i < size; ++i) {
        arr[i] = val;
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print_vec(const vector<int> &vec) {
    for (auto v: vec) {
        cout << v << ", ";
    } 

    cout << endl;
}

unsigned long long fib(unsigned long long n) {
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

void var_scope() {
    static int i {1000};
    cout << "function: i = " << i << endl;
    i += 100;
    cout << "function: i = " << i << endl;
}