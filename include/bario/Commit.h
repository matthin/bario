#pragma once

#include <sys/time.h>
#include <vector>
#include "Contrast.h"

namespace ba {

class Commit {
public:
  Commit(const std::vector<Contrast> contrasts, const std::string& email);

  std::string generateID() const noexcept;
  unsigned long generateDate() const noexcept {
    return time(NULL);
  }

  const std::vector<Contrast> contrasts;
  const std::string email;
  const std::string id;
  const unsigned long date;
};

} // namespace ba

