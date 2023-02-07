#pragma once
#include "CoreMinimal.h"
#include "SelectableName.generated.h"

USTRUCT(BlueprintType)
struct FSelectableName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GAMEPLAYMODS_API FSelectableName();
};

