#include <catch.hpp>
#include "Commit.h"
#include <string>
#include <sys/time.h>
#include <vector>

TEST_CASE("Commit stores required data", "[Commit]") {
  const std::vector<ba::Contrast> contrasts = {
    ba::Contrast("index.html", "Hello")
  };
  const std::string email("example@test.com");
  const ba::Commit commit(contrasts, email);
  REQUIRE(commit.contrasts == contrasts);
  REQUIRE(commit.email == email);
}

TEST_CASE("Commit creates ID") {
  const ba::Commit commit({
    ba::Contrast("index.html", "Hello")
  }, "example@test.com");
  REQUIRE(commit.id.length() > 0);
}

TEST_CASE("Commit creates date") {
  const auto startDate = time(NULL);
  const ba::Commit commit({
    ba::Contrast("index.html", "Hello")
  }, "example@test.com");
  const auto endDate = time(NULL);
  REQUIRE(startDate <= commit.date <= endDate);
}

