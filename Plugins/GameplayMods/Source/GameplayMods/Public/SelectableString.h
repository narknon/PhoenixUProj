#pragma once
#include "CoreMinimal.h"
#include "SelectableString.generated.h"

USTRUCT(BlueprintType)
struct FSelectableString {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString String;
    
    GAMEPLAYMODS_API FSelectableString();
};

