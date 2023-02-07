#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesVectorName.h"
#include "LerpVolumeVectorIndoorsOutdoorsInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeVectorIndoorsOutdoorsInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesVectorName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector IndoorsValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OutdoorsValue;
    
    ULerpVolumeVectorIndoorsOutdoorsInterpolant();
};

