#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "CameraStackPrimaryCameraTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackPrimaryCameraTargetGetter : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OffsetFromTarget;
    
    UCameraStackPrimaryCameraTargetGetter();
};

