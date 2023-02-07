#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "LerpVolumesInterpolants.h"
#include "LerpVolumesLibrary.generated.h"

class ULerpVolumeFinalInterpolant;
class ULerpVolumeInterpolant;

UCLASS(Blueprintable)
class LERPVOLUMES_API ULerpVolumesLibrary : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> VolumeCollisionChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolants Interpolants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumeInterpolant*> DefaultInterpolants;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultInterpolantsPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumeFinalInterpolant*> FinalInterpolants;
    
    ULerpVolumesLibrary();
};

