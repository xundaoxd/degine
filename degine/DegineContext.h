#pragma once
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "degine/Engine.h"
#include "degine/Loader.h"
#include "degine/ir/Graph.h"

namespace degine {

class DegineContext;

class DegineContext {

public:
  Graph Load(std::string fname, std::string format = "") {
    if (format.empty()) {
      format = fname.substr(fname.find_last_of(".") + 1);
    }
    if (format.empty()) {
      throw std::invalid_argument("empty model format");
    }
    return LoaderRegistry::Instance()->GetLoader(format)->Load(fname);
  }

  Graph NewGraph(std::string nspace) { return Graph{}; }

  Engine Build(Graph g) {
    // TODO: impl
    return Engine{};
  }
};

} // namespace degine
