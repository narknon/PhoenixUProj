#pragma once
#include "CoreMinimal.h"
#include "MapIconEntry.h"
#include "MapIconListContainer.generated.h"

USTRUCT(BlueprintType)
struct FMapIconListContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapIconEntry> IconList;
    
    PHOENIX_API FMapIconListContainer();
};

