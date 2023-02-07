#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesPresistentContextDataBase.h"
#include "LerpVolumesTagEntry.h"
#include "LerpVolumesFinalTagHistory.generated.h"

UCLASS(Blueprintable)
class LERPVOLUMES_API ULerpVolumesFinalTagHistory : public ULerpVolumesPresistentContextDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagEntry Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagEntry Prior;
    
    ULerpVolumesFinalTagHistory();
};

