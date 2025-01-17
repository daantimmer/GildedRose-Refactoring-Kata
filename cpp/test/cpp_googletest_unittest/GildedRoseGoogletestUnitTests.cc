#include "GildedRose.h"
#include <gtest/gtest.h>

TEST(GildedRoseTest, Foo) {
  vector<Item> items;
  items.push_back(Item("Foo", 0, 0));
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Foo", app.items[0].name);
}
