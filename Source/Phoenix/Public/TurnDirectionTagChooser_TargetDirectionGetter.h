#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TurnDirectionTagChooser_TargetDirectionGetter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class UTurnDirectionTagChooser_TargetDirectionGetter : public UObject {
    GENERATED_BODY()
public:
    UTurnDirectionTagChooser_TargetDirectionGetter();
};

