#pragma once
#include "CoreMinimal.h"
#include "ELerpVolumesTagValueMode.h"
#include "LerpVolumesInterpolantBase.h"
#include "LerpVolumesTagEntry.h"
#include "LerpVolumesTag.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesTag : public FLerpVolumesInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagEntry DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlphaTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceFullHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySetDefaultWWiseRTPCIfNotEmpty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLerpVolumesTagEntry> History;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELerpVolumesTagValueMode DefaultValueMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELerpVolumesTagValueMode RTPCValueMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELerpVolumesTagValueMode HermesValueMode;
    
    LERPVOLUMES_API FLerpVolumesTag();
};

