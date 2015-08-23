#include <catch.hpp>
#include "Commit.h"
#include <ctime>
#include <string>
#include <vector>

TEST_CASE("General Commit tests", "[Commit]") {
  const std::vector<ba::Contrast> contrasts = {
    ba::Contrast("index.html", "Hello")
  };
  const std::string email("example@test.com");
  const std::string message("Example message");
  const auto startDate = std::time(nullptr);
  const ba::Commit commit(contrasts, email, message);

  SECTION("Commit stores required data", "[Commit]") {
    REQUIRE(commit.contrasts == contrasts);
    REQUIRE(commit.email == email);
    REQUIRE(commit.message == message);
  }

  SECTION("Commit creates ID") {
    REQUIRE(commit.id.length() > 0);
  }

  SECTION("Commit creates date") {
    const auto endDate = std::time(nullptr);
    REQUIRE(startDate <= commit.date <= endDate);
  }
}

