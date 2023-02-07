#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsBoundComponent.h"
#include "GlobalLightGroupsBoundComponentList.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FGlobalLightGroupsBoundComponentList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGlobalLightGroupsBoundComponent> Components;
    
    FGlobalLightGroupsBoundComponentList();
};

