#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsFindBestRegion.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsFindBestRegion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsFindBestRegion();
};

