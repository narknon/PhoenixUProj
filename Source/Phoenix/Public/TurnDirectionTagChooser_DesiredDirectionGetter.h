#pragma once
#include "CoreMinimal.h"
#include "TurnDirectionTagChooser_TargetDirectionGetter.h"
#include "TurnDirectionTagChooser_DesiredDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnDirectionTagChooser_DesiredDirectionGetter : public UTurnDirectionTagChooser_TargetDirectionGetter {
    GENERATED_BODY()
public:
    UTurnDirectionTagChooser_DesiredDirectionGetter();
};

