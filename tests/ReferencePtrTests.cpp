#include <cstddef>

#include <gtest/gtest.h>

#include "ReferencePtr.h"

namespace {

class ReferenceCountedObject {
public:
    void add_ref() {
        ++reference_count;
    }

    void release() {
        --reference_count;
    }

    int reference_count = 0;
};

TEST(ReferencePtrTest, DefaultConstructedPointerIsEmpty) {
    const ReferencePtr<ReferenceCountedObject> pointer;

    EXPECT_FALSE(pointer);
    EXPECT_EQ(pointer.get_ptr(), nullptr);
}

TEST(ReferencePtrTest, CopiesManageReferenceCount) {
    ReferenceCountedObject object;

    {
        ReferencePtr<ReferenceCountedObject> first(&object);
        EXPECT_EQ(object.reference_count, 1);

        {
            const ReferencePtr<ReferenceCountedObject> second(first);

            EXPECT_EQ(object.reference_count, 2);
            EXPECT_EQ(second.get_ptr(), &object);
        }

        EXPECT_EQ(object.reference_count, 1);
    }

    EXPECT_EQ(object.reference_count, 0);
}

} // namespace
