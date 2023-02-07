#pragma once
#include "CoreMinimal.h"
#include "OutfitType.generated.h"

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FOutfitType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FOutfitType();
};

