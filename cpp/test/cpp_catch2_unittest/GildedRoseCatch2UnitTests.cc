#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include "GildedRose.h"
#include "catch2/catch_all.hpp"

TEST_CASE("GildedRoseUnitTest", "Foo") {
  vector<Item> items;
  items.push_back(Item("Foo", 0, 0));
  GildedRose app(items);
  app.updateQuality();
  REQUIRE("Foo" == app.items[0].name);
}
