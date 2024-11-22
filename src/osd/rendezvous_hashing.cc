// #include "rendezvous_hashing.hh"
// #include <vector>

// std::shared_ptr<rendezvousNode> determine_responsible_node(std::vector<std::shared_ptr<rendezvousNode>> &nodes, std::string key){
//   double max_score = 0.0;
//   std::shared_ptr<rendezvousNode> responsible_node = nullptr;
//   for(auto &node : nodes){
//     auto score = node->compute_weighted_score(key);
//     if(score > max_score){
//       max_score = score;
//       responsible_node = node;
//     }
//   }
//   return responsible_node;
// } 