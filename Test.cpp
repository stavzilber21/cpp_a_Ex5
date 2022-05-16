#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace std;
using namespace ariel;
TEST_CASE("organization one") {
    OrgChart organization;
    CHECK_THROWS(organization.add_sub("miri", "ofek"));
    CHECK(organization.add_root("elka"));
    CHECK(organization.add_sub("elka", "miri"));
    CHECK_THROWS(organization.add_sub("stav", "aner"));
    CHECK(organization.add_sub("miri", "ayalon"));
    CHECK(organization.add_sub("miri", "nofar"));
    CHECK(organization.add_sub("miri", "stav"));

/* Prints the org chart in a reasonable format. For example:
       elka
       |
       miri
       |--------|--------|
       ayalon   nofar     stav
 */
    string ans;
    for (auto iter = organization.begin_level_order(); iter != organization.end_level_order(); iter++) {
        if (iter++ != organization.end_level_order()) {
            ans += *iter + "|";
        } else
            ans += *iter;
    }
    CHECK_EQ(ans, "elka|miri|ayalon|nofar|stav");
    CHECK_FALSE(ans == "stav");
    ans.clear();

    for (auto iter = organization.begin_reverse_order(); iter != organization.reverse_order(); iter++) {
        if (iter++ != organization.end_level_order()) {
            ans += *iter + "|";
        } else
            ans += *iter;
    }
    CHECK_EQ(ans, "ayalon|nofar|stav|miri|elka");
    ans.clear();

    for (auto iter = organization.begin_preorder(); iter != organization.end_preorder(); iter++) {
        if (iter++ != organization.end_level_order()) {
            ans += *iter + "|";
        } else
            ans += *iter;
    }
    CHECK_EQ(ans, "elka|miri|ayalon|nofar|stav");
    CHECK_FALSE(ans == "|");
    ans.clear();
    CHECK(organization.add_root("frida"));
}


TEST_CASE("organization two"){
    OrgChart organization2;
    CHECK_THROWS(organization2.add_sub("erel", "mor"));
    CHECK(organization2.add_root("erel"));
    CHECK(organization2.add_sub("erel", "mor"));
    CHECK(organization2.add_sub("erel", "haim"));
    CHECK(organization2.add_sub("mor", "nofar"));
    CHECK(organization2.add_sub("haim", "tal"));
    CHECK_THROWS(organization2.add_sub("diana", "yavgeni"));
    /* Prints the org chart in a reasonable format. For example:
       erel
       |--------|
      mor      haim
       |--------|
       nofar   tal
 */

    vector<string>vec = {"erel","mor","haim","nofar","tal"};
    unsigned int i = 0;
    for (auto iter = organization2.begin_level_order(); iter != organization2.begin_level_order(); iter++) {
        CHECK_EQ(vec.at(i++), (*iter));
    }
    string ans;
    for (auto iter = organization2.begin_reverse_order(); iter != organization2.reverse_order(); iter++) {
        if (iter++ != organization2.end_level_order()) {
            ans += *iter + "|";
        } else
            ans += *iter;
    }
    CHECK_EQ(ans, "nofer|tal|mor|haim|erel");
    CHECK_FALSE(ans == "erel is the root");
    ans.clear();
}

TEST_CASE("organization three"){
    OrgChart organization3;
    CHECK_THROWS(organization3.add_sub("1", "2"));
    CHECK(organization3.add_root("1"));
    CHECK(organization3.add_sub("1", "2"));
    CHECK(organization3.add_sub("2", "3"));
    CHECK(organization3.add_sub("3", "4"));
    /* Prints the org chart in a reasonable format. For example:
   1
   |
   2
   |
   3
   |
   4
*/
    auto iter = organization3.begin_level_order();
    for (unsigned int i = 0; i < 3; ++i) {
        iter++;
    }
    CHECK_THROWS(iter++);
}

