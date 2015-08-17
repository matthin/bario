#pragma once

#include <vector>
#include "Contrast.h"

namespace ba {

class Commit {
public:
  Commit(const std::vector<Contrast> contrasts) : contrasts(contrasts) {}
  const std::vector<Contrast> contrasts;
};

} // namespace ba

