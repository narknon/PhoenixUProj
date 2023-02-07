#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeDynamicTagInterpolant.h"
#include "LerpVolumeDBLocationTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULerpVolumeDBLocationTagInterpolant : public ULerpVolumeDynamicTagInterpolant {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LocationName;
    
public:
    ULerpVolumeDBLocationTagInterpolant();
};

