#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetter.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackMountCreatureGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackMountCreatureGetter : public UCameraStackSecondaryTargetGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OffsetFromCreature;
    
    UCameraStackMountCreatureGetter();
};

