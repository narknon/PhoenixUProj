#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumeInterpolant.h"
#include "LerpVolumesColorName.h"
#include "LerpVolumeColorIndoorsOutdoorsInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeColorIndoorsOutdoorsInterpolant : public ULerpVolumeInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesColorName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor IndoorsValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor OutdoorsValue;
    
    ULerpVolumeColorIndoorsOutdoorsInterpolant();
};

