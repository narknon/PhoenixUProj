#pragma once
#include "CoreMinimal.h"
#include "CameraStackSplineGetter.h"
#include "CameraStackBroomFlightGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBroomFlightGetter : public UCameraStackSplineGetter {
    GENERATED_BODY()
public:
    UCameraStackBroomFlightGetter();
};

