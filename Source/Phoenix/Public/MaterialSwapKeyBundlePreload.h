#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialSwapKeyBundlePreload.generated.h"

USTRUCT(BlueprintType)
struct FMaterialSwapKeyBundlePreload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttachedChildren;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bComponentChildren;
    
    PHOENIX_API FMaterialSwapKeyBundlePreload();
};

