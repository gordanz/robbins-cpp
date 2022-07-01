#include <omp.h>

int main()
{
int target_thread_num = 4;
omp_set_num_threads(target_thread_num);
unsigned long times[target_thread_num];

// Initialize all the times
#pragma omp parallel
{
   int thread_id = omp_get_thread_num();
   std::cout << "Thread number: " << omp_get_thread_num() << endl;
}

}


