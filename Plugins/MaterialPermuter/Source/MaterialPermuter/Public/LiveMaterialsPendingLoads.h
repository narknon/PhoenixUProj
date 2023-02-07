#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LiveMaterialsPendingLoad.h"
#include "LiveMaterialsPendingLoads.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FLiveMaterialsPendingLoads {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FSoftObjectPath, FLiveMaterialsPendingLoad> PendingLoads;
    
    FLiveMaterialsPendingLoads();
};

