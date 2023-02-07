#pragma once
#include "CoreMinimal.h"
#include "CameraStackSplineGetter.h"
#include "CameraStackNamedSplineGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackNamedSplineGetter : public UCameraStackSplineGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SplineActorName;
    
    UCameraStackNamedSplineGetter();
};

