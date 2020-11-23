#ifndef TRAP_TEST_HPP
#define TRAP_TEST_HPP

#include "gtest/gtest.h"
#include "../../header/factory/trap.hpp"

TEST(TrapTest, NonEmptyVariables) {
    Trap* trap = new Trap();

    EXPECT_NE(trap->getName(), "");
    EXPECT_NE(trap->getEffects(), "");

    delete trap;
}

TEST(TrapTest, SetEmptyVariables) {
    Trap* trap = new Trap("", "");

    EXPECT_EQ(trap->getName(), "");
    EXPECT_EQ(trap->getEffects(), "");

    delete trap;
}

TEST(TrapTest, SetVariables) {
    Trap* trap = new Trap("Pencil", "Slowness");

    EXPECT_EQ(trap->getName(), "Pencil");
    EXPECT_EQ(trap->getEffects(), "Slowness");

    delete trap;
}

#endif // TRAP_TEST