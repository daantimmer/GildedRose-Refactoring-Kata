#include "GildedRose.h"

namespace
{
    bool IsHandOfRagnaros(const Item &item)
    {
        return item.name == "Sulfuras, Hand of Ragnaros";
    }

    bool IsBackstageName(const Item& item)
    {
        return item.name == "Backstage passes to a TAFKAL80ETC concert";
    }
}

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && !IsBackstageName(items[i]))
        {
            if (items[i].quality > 0)
            {
                if (! IsHandOfRagnaros(items[i]))
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (IsBackstageName(items[i]))
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (! IsHandOfRagnaros(items[i]))
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != "Aged Brie")
            {
                if (!IsBackstageName(items[i]))
                {
                    if (items[i].quality > 0)
                    {
                        if (! IsHandOfRagnaros(items[i]))
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}
