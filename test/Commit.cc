#include <catch.hpp>
#include "Commit.h"
#include <vector>

TEST_CASE("Commit stores required data", "[Commit]") {
  const std::vector<ba::Contrast> contrasts = {
    ba::Contrast("index.html", "Hello")
  };
  const ba::Commit commit(contrasts);
  REQUIRE(commit.contrasts == contrasts);
}

TEST_CASE("Commit creates ID") {
  const ba::Commit commit({
    ba::Contrast("index.html", "Hello")
  });
  REQUIRE(commit.id.length() > 0);
}

