#pragma once
#include "CoreMinimal.h"
#include "SelectableSubobjectName.h"
#include "DynamicNavComponentInfo.generated.h"

USTRUCT(BlueprintType)
struct FDynamicNavComponentInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableSubobjectName NavigationPrimitiveName;
    
    PHOENIX_API FDynamicNavComponentInfo();
};

