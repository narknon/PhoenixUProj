#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "TimeRigCoordinate.h"
#include "Float_TimeRigCoordinate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UFloat_TimeRigCoordinate : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigCoordinate Value;
    
    UFloat_TimeRigCoordinate();
};

