#pragma once
#include "CoreMinimal.h"
#include "PSOCachingComponentActivateDelegateDelegate.h"
#include "PSOCachingComponentResetDelegateDelegate.h"
#include "PreviewAssetTypeData.generated.h"

USTRUCT(BlueprintType)
struct FPreviewAssetTypeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPSOCachingComponentActivateDelegate ActivateDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPSOCachingComponentResetDelegate ResetDelegate;
    
    PSOCACHING_API FPreviewAssetTypeData();
};

