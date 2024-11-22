// #pragma once
// #include <string>
// #include <cmath>
// #include <vector>
// #include <memory>
// class rendezvousNode {
// public:
//   rendezvousNode(const std::string &id, const double weight): id_(id), weight_(weight) {};
//   double compute_weighted_score(std::string key){
//     auto score = hash_to_unit_interval(id_ + ":" + key);
//     double log_score = 1.0 / -std::log(score);
//     // std::cout <<  "id:" << id_ << " score:" << score << " log_score: " << log_score << std::endl;
//     return weight_ * log_score;
//   }

//   auto get_id() -> std::string const { return id_; }
//   auto get_weight() -> double const { return weight_; }
// private:
//   std::string id_;
//   double weight_;
//   double hash_to_unit_interval(const std::string& id) {
//     std::hash<std::string> hasher;
//     auto hash = hasher(id);
//     auto d1 = (static_cast<double>(hash) + 1.0);
//     auto d2 = (static_cast<double>(UINT64_MAX) + 1.0);
//     // std::cout << "hash: " << hash << " d1: " << d1 << " d2: " << d2 << std::endl;
//     // std::cout << "hash: " << hash << " d1: " << d1 << " d2: " << d2 << " d1/d2: " << d1 / d2 << std::endl;
//     return d1 / d2;
//   }
// };
// std::shared_ptr<rendezvousNode> determine_responsible_node(std::vector<std::shared_ptr<rendezvousNode>> &nodes, std::string key);