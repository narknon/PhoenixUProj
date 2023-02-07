#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesPresistentContextDataBase.h"
#include "LerpVolumesTagEntry.h"
#include "LerpVolumesLastValidTag.generated.h"

UCLASS(Blueprintable)
class LERPVOLUMES_API ULerpVolumesLastValidTag : public ULerpVolumesPresistentContextDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagEntry LastValid;
    
    ULerpVolumesLastValidTag();
};

