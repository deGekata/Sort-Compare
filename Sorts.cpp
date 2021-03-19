#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
//###################################################################################################################################################
//###################################Merge_sort######################################################################################################
void Merge(uint64_t temp_mas[], uint64_t left, uint64_t mid, uint64_t right) {
    uint64_t n1, n2, i, j, k;
    n1 = mid - left + 1;
    n2 = right-mid;
    uint64_t* Left = new uint64_t[ n1 ];
    uint64_t* Right = new uint64_t[ n2 ];
    for (i = 0; i < n1; ++i) {
        Left[ i ] = temp_mas[ left + i ];
    }
    for (j = 0; j < n2; ++j) {
        Right[j] = temp_mas[ mid + j + 1];
    }
    i = 0, j = 0;
    for (k = left;i < n1 && j < n2; ++k) {
         if (Left[ i ] < Right[ j ]) {
            temp_mas[ k ] = Left[ i++ ];
        } else {
            temp_mas[ k ] = Right[ j++ ];
        }
    }
    while (i < n1) {
        temp_mas[ k++ ]= Left[ i++ ];
    }
    while (j < n2) {
        temp_mas[ k++ ] = Right[ j++ ];
    }
}
int MergeSort (uint64_t temp_mas[], uint64_t l_part, uint64_t r_part) {
    uint64_t mid;
    if (l_part < r_part) {
        mid=(l_part + r_part) / 2;
        MergeSort(temp_mas, l_part, mid);
        MergeSort(temp_mas, mid + 1, r_part);
        Merge(temp_mas, l_part, mid, r_part);
    }
}
//###################################################################################################################################################
//###################################################################################################################################################
uint64_t get_byte(size_t num, int ord_num, int bytes_to_take){
    return ((unsigned long long)num << ((sizeof (num) - bytes_to_take - ord_num * bytes_to_take) * 8)) >> (sizeof (num) * 8 - 8 * bytes_to_take);
}

void Radix_sort(uint64_t Temp[], int length, int bytes_to_take) {
     int cnt_bytes = sizeof (Temp[0]) / bytes_to_take;
     //std::cout << " bytes " << cnt_bytes << "\n";
     int cnt = pow(2, bytes_to_take * 8);
     uint64_t* Temp2 = new uint64_t[length];
     for (int byte = 0; byte < cnt_bytes; ++byte) {
         std::vector<int> byte_var(cnt,0);
         //std::cout << "byte_num: " << byte << "\n";
         for (int iter = 0; iter < length; ++iter) {
             byte_var[get_byte(Temp[iter], byte, bytes_to_take)]++;
             //std::cout << get_byte(Temp[iter], byte, bytes_to_take) << " " << Temp[iter] << "\n";
         }

         int count = 0;
         int temp;
         for (int iter = 0; iter < cnt; ++iter) {
             temp = byte_var[ iter ];
             byte_var[ iter ] = count;
             count += temp;
         }
         //std::cout<<"swaped\n";
         for (int iter = 0; iter < length; ++iter) {
             temp = get_byte(Temp[ iter ], byte, bytes_to_take);
             Temp2[byte_var[temp]] = Temp[ iter ];
             byte_var[ temp ]++;
         }
         std::swap(Temp, Temp2);
         //std::cout<<"swaped\n";
     }
     return;
}
//###################################################################################################################################################
//###################################################################################################################################################

std::vector<uint64_t> get_steps(uint64_t N){
    std::vector<uint64_t> steps;
    uint64_t for_two, for_three;
    for_two  = 1;
    for_three = 3;
    N /= 2;
    //  std::cout << N << " dsfads\n";
    while (for_two < N){
        steps.push_back(for_two);
        for_three = 3;
        while (for_two * for_three < N) {
            steps.push_back(for_two * for_three);
            for_three *= 3;
        }
        for_two *= 2;
    }
    std::sort(steps.begin(), steps.end());
    return  steps;
}
int Shell_Sort(uint64_t arr[], int N) {
    std::vector<uint64_t> steps = get_steps(N);
    // Start with a big gap, then reduce the gap
    for (int step_num = steps.size() - 1; step_num >= 0; --step_num) {
        int gap = steps[ step_num ];
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < N; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

int Casual_shellSort(uint64_t arr[], int N)
{
    // Start with a big gap, then reduce the gap
    for (int gap = N/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < N; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}



//######################################################## Super SHEEEEEll    ##################################################################################
void Super_Shell_Sort(uint64_t a[], int l, int r) {
    int n = r - l;
    std::vector<int> steps;
    steps.push_back(1);
    while (steps.back() < n) {
        int s = steps.back();
        steps.push_back(s * 4 - s / 5);
    }
    for (int q = steps.size() - 1; q >= 0; --q) {
        int step = steps[ q ];
        for (int i = l + step; i < r; ++i) {
            int j = i, diff = j - step;
            while (diff >= l && a[diff] > a[j]) {
                std::swap(a[diff], a[j]);
                j = diff;
                diff = j - step;
            }
        }
    }
}




//####################################################################################################################################################################




void My_Qsort(uint64_t a[], int l, int r) {
    if (r - l <= 1) return;
    uint64_t z = a[rand() % (r - l) + l];
    uint64_t ll = l, rr = r - 1;
    while (ll < rr) {
        while (a[ll] < z) ll++;
        while (a[rr] > z) rr--;
        if (ll <= rr) std::swap(a[ll++], a[rr--]);
    }
    if (l < rr) My_Qsort(a, l, rr + 1);
    if (ll < r) My_Qsort(a, ll, r);
}






void old_qsort(uint64_t *A, uint64_t  L, uint64_t R) {
    if (R - L <= 1) return;
    uint64_t mid = A[L + rand() % (R - L)];
    int x = L, y = L;
    for (int i = L; i < R; ++i)
    {
        if (A[i] < mid){
            std::swap(A[x], A[i]);
            if (x != y) std::swap(A[y], A[i]);
            ++x; ++y;
        }

        else
            if (A[i] == mid){
                std::swap(A[y], A[i]);
                ++y;
            }

    }
    old_qsort(A, L, x);
    old_qsort(A, y, R);
}
