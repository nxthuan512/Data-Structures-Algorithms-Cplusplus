#include "main.hpp"

void move_disk(int n_disks, Stack stackA, Stack stackB, Stack stackC) {
   if (n_disks == 1) {
      std::cout << "Move disk from " << stackA << " to " << stackC << std::endl;
   } else {
      move_disk(n_disks-1, stackA, stackC, stackB);
      std::cout << "Move disk from " << stackA << " to " << stackC << std::endl;
      move_disk(n_disks-1, stackB, stackA, stackC);
   }
}

int main() {
   int n_disks = 6;
   for (int i = 1; i < n_disks; ++i) {
      std::cout << "====== N_DISKS = " << i << " ======" << std::endl;
      move_disk(i, stackA, stackB, stackC);
   }
   return 0;
}
