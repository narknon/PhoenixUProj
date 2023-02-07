#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpWindowFinder.h"
#include "AvaEmptyMotionWarpWindowFinder.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class AMBULATORY_API UAvaEmptyMotionWarpWindowFinder : public UAvaMotionWarpWindowFinder {
    GENERATED_BODY()
public:
    UAvaEmptyMotionWarpWindowFinder();
};

