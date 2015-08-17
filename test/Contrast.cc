#include <catch.hpp>
#include "Contrast.h"

TEST_CASE("Contrast stores required data", "[Contrast]") {
  const ba::Contrast contrast("index.txt", "Hello");
  REQUIRE(contrast.file == "index.txt");
  REQUIRE(contrast.modifiedText == "Hello");
}

