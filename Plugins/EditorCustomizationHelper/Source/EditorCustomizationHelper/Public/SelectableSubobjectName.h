#pragma once
#include "CoreMinimal.h"
#include "SelectableSubobjectName.generated.h"

USTRUCT(BlueprintType)
struct FSelectableSubobjectName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    EDITORCUSTOMIZATIONHELPER_API FSelectableSubobjectName();
};

