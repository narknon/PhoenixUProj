#pragma once
#include "CoreMinimal.h"
#include "AvatarHouse.generated.h"

USTRUCT(BlueprintType)
struct FAvatarHouse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    PHOENIX_API FAvatarHouse();
};

