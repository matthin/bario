#pragma once

#include <string>

namespace ba {

struct Contrast {
public:
  Contrast(const std::string& file, const std::string& modifiedText) noexcept
    : file(std::move(file)), modifiedText(std::move(modifiedText)) {}

  const std::string file;
  const std::string modifiedText;

  bool operator ==(const Contrast& other) const {
    return (file == other.file && modifiedText == other.modifiedText);
  }
  bool operator !=(const Contrast& other) const {
    return !(*this == other);
  }
};

} // namespace ba

