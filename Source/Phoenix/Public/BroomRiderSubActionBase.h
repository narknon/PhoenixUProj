#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionBase.h"
#include "BroomRiderSubActionBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderSubActionBase : public UBroomRiderActionBase {
    GENERATED_BODY()
public:
    UBroomRiderSubActionBase();
};

