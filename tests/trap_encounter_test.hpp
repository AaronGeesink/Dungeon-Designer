#ifndef TRAP_ENCOUNTER_TEST_HPP
#define TRAP_ENCOUNTER_TEST_HPP

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include "../header/factory/trap_encounter.hpp"
#include "../header/factory/trap.hpp"

TEST(TrapEncounterTest, EncounterNotEmpty) {
    TrapEncounter* trap = new TrapEncounter();
    EXPECT_NE(trap->getEncounter(), "");
    delete trap;
}

TEST(TrapEncounterTest, GetEncounterHasLoop) {
    TrapEncounter* trap = new TrapEncounter();
    EXPECT_THAT(trap->getEncounter(), ::testing::HasSubstr("Trap Encounter!"));
    delete trap;
}

TEST(TrapEncounterTest, SingleTrap) {
    std::vector<Trap> traps;
    traps.push_back(Trap("Waterslide", "Slippery Toes"));

    TrapEncounter* trap = new TrapEncounter(traps);

    EXPECT_EQ(trap->getEncounter(), "Trap Encounter!\n\tWaterslide causing Slippery Toes.");

    delete trap;
}

TEST(TrapEncounterTest, ThreeTrap) {
    std::vector<Trap> traps;
    traps.push_back(Trap("Waterslide", "Slippery Toes"));
    traps.push_back(Trap("Bear Trap", "Pain and Suffering"));
    traps.push_back(Trap("Hidden Electromagnet", "Brain Melt"));

    TrapEncounter* trap = new TrapEncounter(traps);

    EXPECT_EQ(trap->getEncounter(), "Trap Encounter!\n\tWaterslide causing Slippery Toes.\n\tBear Trap causing Pain and Suffering.\n\tHidden Electromagnet causing Brain Melt.");

    delete trap;
}

#endif // TRAP_ENCOUNTER_TEST_HPP