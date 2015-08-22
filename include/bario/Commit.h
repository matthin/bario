#pragma once

#include <ctime>
#include <vector>
#include "Contrast.h"

namespace ba {

class Commit {
public:
  Commit(
    const std::vector<Contrast> contrasts, const std::string& email,
    const std::string& message
  ) noexcept;

  std::string generateID() const noexcept;
  std::time_t generateDate() const noexcept {
    return std::time(nullptr);
  }

  const std::vector<Contrast> contrasts;
  const std::string email;
  const std::string message;
  const std::string id;
  const std::time_t date;
};

} // namespace ba

