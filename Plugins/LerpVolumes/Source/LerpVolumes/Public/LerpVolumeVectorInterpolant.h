#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesVectorName.h"
#include "LerpVolumeVectorInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeVectorInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesVectorName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    ULerpVolumeVectorInterpolant();
};

