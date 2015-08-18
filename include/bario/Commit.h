#pragma once

#include <vector>
#include "Contrast.h"

namespace ba {

class Commit {
public:
  Commit(const std::vector<Contrast> contrasts);

  std::string generateID() const noexcept;

  const std::vector<Contrast> contrasts;
  const std::string id;
};

} // namespace ba

