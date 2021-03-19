#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <cstdint>
#include <chrono>
#include <Sorts.cpp>

using namespace std;


vector<uint64_t> cnt = {8, 21, 144, 987, 4181, 6765, 46368, 2178309, 102334155};
int iter = 0;

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
    return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
int main() {
    for (auto count:cnt) {
        srand(time(NULL));
        int N;
        uint64_t A = 0;
        uint64_t B = 17446744073709551615;
        N = count;
        cout << N << "\n";
        uint64_t* Mas = new uint64_t[N];
        for (int i = 0; i < N; ++i){
            Mas[i] = ((double) rand() / (RAND_MAX)) * B;
        }
        uint64_t* Temp = new uint64_t[N];
        std::chrono::high_resolution_clock::time_point start;
        std::chrono::high_resolution_clock::time_point end;
        auto int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        uint64_t seconds = int_nsc.count();

        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        //############################################## RADIX SORT ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        start = std::chrono::high_resolution_clock::now();
        Radix_sort(Temp, N, 1);
        end =std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*
    for (int i = 0; i < N; ++i){
        cout << Temp[i] << "\n";
    }
    //cout << "\n";
*/
        cout << seconds << ": Radix sort\n\n";
        //####################################################################################################################################################################









        //######################################################## STD::Sort   ##################################################################################
        vector<int> tmp(N);
        for(int i = 0; i < N; ++i){
            tmp[i] = Mas[i];
        }
        start = std::chrono::high_resolution_clock::now();
        sort(tmp.begin(), tmp.end());
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*
    for (int i = 0; i < N; ++i){
        cout << tmp[i] << "\n";
    }
    //cout << "\n";
*/
        cout << seconds << ": Std::sort included\n";
        /*
    for (int i = 0; i < N; ++i){
        cout << Mas[i] << "\n";
    }*/

        /*for(auto i:get_steps(N)){
        cout << i << ' ';
    }*/
        cout << "\n";
        //####################################################################################################################################################################




        //######################################################## My old quick sort  ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        //cout << seconds << "\n";
        start = std::chrono::system_clock::now();
        old_qsort(Temp, 0, N);
        end = std::chrono::system_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*for (int i = 0; i < N; ++i) {
        cout << Temp[i] << "\n";
    }*/
        cout << seconds << ": My old Qsort\n\n";
        //####################################################################################################################################################################



        /*  //######################################################## My quick sort  ##################################################################################
    for(int i = 0; i < N; ++i){
        Temp[i] = Mas[i];
    }
    //cout << seconds << "\n";
    start = std::chrono::system_clock::now();
    My_Qsort(Temp, 0 , N);
    end = std::chrono::system_clock::now();
    int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    seconds = int_nsc.count();

    /*for (int i = 0; i < N; ++i) {
        cout << Temp[i] << "\n";
    }*/
        //cout << seconds << ": My_Qsort\n\n";
        //####################################################################################################################################################################




        //######################################################## Qsort INCLUDED  ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        start =std::chrono::high_resolution_clock::now();
        qsort(Temp, N, sizeof (int), compare);
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*
        for (int i = 0; i < N; ++i){
            cout << Temp[i] << "\n";
        }
        //cout << "\n";
    */
        cout << seconds << ": Qsort included\n\n";
        //####################################################################################################################################################################



        //######################################################## Another one Shell Sort    ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        //cout << seconds << "\n";
        start = std::chrono::high_resolution_clock::now();
        Super_Shell_Sort(Temp,0 , N);
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*for (int i = 0; i < N; ++i) {
        cout << Temp[i] << "\n";
    }*/
        cout << seconds << ": Another one Shell\n\n";
        //####################################################################################################################################################################





        //######################################################## Casual Shell SORT    ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        //cout << seconds << "\n";
        start = std::chrono::high_resolution_clock::now();
        Casual_shellSort(Temp, N);
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*for (int i = 0; i < N; ++i) {
        cout << Temp[i] << "\n";
    }*/
        cout << seconds << ": Casual Shell\n\n";


        //######################################################## Shell Sort    ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        //cout << seconds << "\n";
        start = std::chrono::high_resolution_clock::now();
        Shell_Sort(Temp, N);
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*for (int i = 0; i < N; ++i) {
        cout << Temp[i] << "\n";
    }*/
        cout << seconds << ": Shell\n\n";
        //####################################################################################################################################################################




        //######################################################## MERGE SORT    ##################################################################################
        for(int i = 0; i < N; ++i){
            Temp[i] = Mas[i];
        }
        start = std::chrono::high_resolution_clock::now();
        MergeSort(Temp, 0, N - 1);
        end = std::chrono::high_resolution_clock::now();
        int_nsc = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        seconds = int_nsc.count();

        /*
        for (int i = 0; i < N; ++i){
            cout << Temp[i] << "\n";
        }1
        cout << "\n";
    */
        cout << seconds << ": Merge\n\n\n\n\n\n\n\n\n\n\n\n\n";

        //####################################################################################################################################################################
        //    for(int i = 0; i < N; ++i){
        //        cout << Temp[i] << "\n";
        //    }
        cin >> N;
    }
    return 0;
}
