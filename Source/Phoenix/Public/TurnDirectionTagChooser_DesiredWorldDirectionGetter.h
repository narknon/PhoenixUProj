#pragma once
#include "CoreMinimal.h"
#include "TurnDirectionTagChooser_TargetDirectionGetter.h"
#include "TurnDirectionTagChooser_DesiredWorldDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnDirectionTagChooser_DesiredWorldDirectionGetter : public UTurnDirectionTagChooser_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnDirectionTagChooser_DesiredWorldDirectionGetter();
};

