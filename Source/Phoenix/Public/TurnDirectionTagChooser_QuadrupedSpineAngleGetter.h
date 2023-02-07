#pragma once
#include "CoreMinimal.h"
#include "TurnDirectionTagChooser_TargetDirectionGetter.h"
#include "TurnDirectionTagChooser_QuadrupedSpineAngleGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnDirectionTagChooser_QuadrupedSpineAngleGetter : public UTurnDirectionTagChooser_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnDirectionTagChooser_QuadrupedSpineAngleGetter();
};

