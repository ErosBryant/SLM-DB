#include <cstdlib>
#include <fstream>
#include "util/random.h"
#include "util/testutil.h"
#include "nvm_btree.h"

int num_ = 185000000;

int main() {
  leveldb::Random rand(1000);
  BTree* btree = new BTree;
  for (int i = 0; i < num_; i++) {
    uint64_t k = rand.Next() % num_;
    btree->insert(k, &k);
  }
  delete btree;
  printf("debug\n");
  std::this_thread::sleep_for(std::chrono::seconds(100));
}
